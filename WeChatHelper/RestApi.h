#pragma once
#include "HttpServer.h"
#include "mongoose.h"
using namespace std;

string ShowQrPicture(http_message* http_req);
string RestAPISendTextMessage(http_message* http_req);
string GetSelfInformation(http_message* http_req);
string WxLogout(http_message* http_req);
