# Proxy-Updater++
## Author: github.com/SrMilton

Proxy-Updater++ create static local IPs to your rotate proxies from webshare.io.

## Features:
### Auto checker and updater
### Can create many local IPs
### 100% standalone

## How to use:
Change the APIKey with your API from webshare.io in main.h than open the program, it will create static IPs starting with 127.0.0.x:9000, just use those IPs in your program, all requests will be redirect to the current proxy IP. The program checks for new proxies each 2 minutes. BE SURE you are an admin.
![cyex](https://i.imgur.com/Dr9Rsw5.gif)

## Tip:
Sometimes your program freezes for no reason waiting for the user press enter, to prevent this just uncheck QuickEdit mode in your console.
```
Property > Options > Edit Options > QuickEdit Mode
```
![cyex](https://i.stack.imgur.com/mgCgk.gif)

## Requirements:
#### Windows 10 
#### IP Authentication Method in webshare.io
(prob it works on Win7 and 8)


### Useful Links:
[WebShare.io](https://www.webshare.io/) <br />

### Donate (I will remember that):
[Paypal](https://www.paypal.com/donate/?cmd=_donations&business=miltonmanuelcramos@gmail.com&lc=US&item_name=Donation+to+SrMilton&no_note=0&cn=&currency_code=USD&bn=PP-DonationsBF:btn_donateCC_LG.gif:NonHosted&Z3JncnB0=)

```
ps: i know i'm not using json in this program, i had to do this creepy way 
because the program is crashing on my 2° PC when i use json library idk why
```
