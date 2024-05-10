#pragma once
#include <event2/bufferevent.h>

#include "XTask.h"

#include <string>
using namespace std;

struct bufferevent;

class XFtpTask :
	public XTask
{
public:
	string curDir = "/";
	string rootDir = "/";
	string ip = "";
	int port = 0;
//    int testss = 0;
//    static bufferevent *bevv;   // 不行啊
//    int listen_fd = -1;
//    bool state = false;
//    string notProcessType = "";
//    struct evconnlistener *listener;
	XFtpTask *cmdTask = 0;

	// ����Э��
	virtual void Parse(std::string, std::string) {}

	// �ظ�cmd��Ϣ
	void ResCMD(string msg);

	// Detch
	void ConnectoPORT();
	// �ر�����
	void ClosePORT();

    void InitPASV();
    
	// ͨ������ͨ����������
	void Send(const string& data);
	void Send(const char *data, size_t datasize);

	virtual void Event(bufferevent *, short) {}
	virtual void Read(bufferevent *) {}
	virtual void Write(bufferevent *) {}
//    void accept_conn_cb(struct evconnlistener *listener, evutil_socket_t fd,
//                        struct sockaddr *address, int socklen, void *ctx);
//    static void accept_conn_cb();
	void Setcb(struct bufferevent*);
	bool Init() { return true; }

	~XFtpTask();

protected:
//public:
	static void EventCB(bufferevent *, short, void *);
	static void ReadCB(bufferevent *, void *);
	static void WriteCB(bufferevent *, void *);

	// ��CMD����������ͨ������LIST��RETR����������ͨ��
	bufferevent *bev = 0;
	FILE *fp = 0;
};

