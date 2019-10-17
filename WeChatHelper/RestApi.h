#pragma once
#include "HttpServer.h"
#include "mongoose.h"
using namespace std;

string RestAPIShowQrPicture(http_message* http_req);
string RestAPISendTextMessage(http_message* http_req);
string RestAPIGetSelfInformation(http_message* http_req);
string RestAPILogout(http_message* http_req);
string RestAPIGetFriendList(http_message* http_req);
