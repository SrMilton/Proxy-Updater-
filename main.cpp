#include "main.h"

int main()
{
    
    while(true)
    {
        curl = curl_easy_init();
        headers = NULL;
        if (curl)
        {
            headers = curl_slist_append(headers, token.c_str());
            curl_easy_setopt(curl, CURLOPT_URL, "https://proxy.webshare.io/api/proxy/list/");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
        }
        if (res == CURLE_OK)
        {

            first = readBuffer.find("count") + 7;
            count2 = readBuffer.substr(first, last - first); //Pegar só o count
            last = readBuffer.find(',');
            contagem = stoi(count2);
            //cout << contagem << endl;

            first = readBuffer.find("proxy_address") + 16;
            last = readBuffer.find(',', first) - 1;
            ip = readBuffer.substr(first, last - first);

            if (ip.compare(lastip) != 0)
            {
                lastip = ip;
                cout << ">>>" << contagem << " proxies found, creating redirects.." << endl;
                for (i = 1; i < contagem + 1; i++)
                {
                    first = readBuffer.find("proxy_address", rodada) + 16;
                    last = readBuffer.find(',', first) - 1;
                    ip = readBuffer.substr(first, last - first);

                    first = readBuffer.find("ports", rodada) + 15;
                    last = readBuffer.find(',', first);
                    port = readBuffer.substr(first, last - first);
                    //cout << ip << ":" << port << "[" << i << "]" << endl;
                    rodada = last;

                    cmd = "netsh interface portproxy add v4tov4 listenaddress=127.0.0.";
                    cmd = cmd + to_string(i + 24) + " listenport=9000 connectaddress=" + ip + " connectport=" + port;
                    system(cmd.c_str());
                    cout << ">>>" << "127.0.0." << i + 24 << ":9000" << "->" << ip << ":" << port;

                }
                cout << endl;
                cout << "======================================" << endl;
                cout << "[+]Waiting for next rotate of proxies.." << endl;
                Sleep(120000);
                count2.clear();
                ip.clear();
                port.clear();
                readBuffer.clear();
                cmd.clear();
                rodada = 0;
            }
            else
            {
                Sleep(120000);
                count2.clear();
                ip.clear();
                port.clear();
                readBuffer.clear();
                cmd.clear();
                rodada = 0;
            }
        }
        else
        {
            Sleep(120000);
            count2.clear();
            ip.clear();
            port.clear();
            readBuffer.clear();
            cmd.clear();
            rodada = 0;
        }
    }
	return 0;
}