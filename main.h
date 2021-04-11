#define CURL_STATICLIB

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "curl/curl.h"
#include <stdbool.h>
using namespace std;

string APIKey = "ds5d4sd8d26f63eds1d6876s45d963083d4156"; //Change your API Key here (btw this eg is a fake APIKey..)

#ifdef _DEBUG
#pragma comment(lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment(lib, "curl/libcurl_a.lib")
#endif
#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "advapi32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "user32.lib")

int rodada = 0;
string ip;
string port;
string lastip = "";
CURL* curl;
CURLcode res;
string count2;
int i;
unsigned first;
unsigned last;
int contagem;
string cmd;
string readBuffer;
string token = "Authorization: Token " + APIKey;
struct curl_slist* headers = NULL;


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}