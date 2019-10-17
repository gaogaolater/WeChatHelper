#include "stdafx.h"
#include "RestApi.h"
#include "FriendList.h"
#include "HttpServer.h"
#include "mongoose.h"
#include <tchar.h>
using namespace std;

wchar_t* char2wchar(const char* cchar)
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}

string RestAPIShowQrPicture(http_message* http_req)
{
	return "";
}

string RestAPISendTextMessage(http_message* http_req)
{
	//wchar_t* wxid, wchar_t* msg
	char wxid[100]="", msg[1000]="";
	mg_get_http_var(&http_req->query_string, "wxid", wxid, sizeof(wxid));
	mg_get_http_var(&http_req->query_string, "msg", msg, sizeof(msg));
	if (wxid == "") {
		return "{code:-1,msg:'wxid is null'}";
	}
	else if (msg == "") {
		return "{code:-2,msg:'msg is null'}";
	}
	SendTextMessage(char2wchar(wxid), char2wchar(msg));	//发送文本消息
	return "{code:0}";
}

string RestAPIGetSelfInformation(http_message* http_req)
{
	return "";
}

string RestAPILogout(http_message* http_req)
{
	return "";
}

string RestAPIGetFriendList(http_message* http_req)
{
	return GetUserListInfoForRestAPI();
}
