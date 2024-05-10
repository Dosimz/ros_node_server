#pragma once
class XTask
{
public:
	// “ªøÕªß∂À“ª∏ˆbase
	struct event_base *base = 0;
//    struct bufferevent *bevv = 0;
    
	// ¡¨Ω”µƒsock
	int sock = 0;

	// œﬂ≥Ã≥ÿid
	int thread_id = 0;

	// ≥ı ºªØ»ŒŒÒ
	virtual bool Init() = 0;
};

