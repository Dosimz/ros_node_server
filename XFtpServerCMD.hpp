#pragma once
#include "XFtpTask.h"

#include <map>

class XFtpServerCMD : public XFtpTask
{
public:
    
	// ≥ı ºªØ»ŒŒÒ
	virtual bool Init();

	virtual void Event(bufferevent *be, short events);

	virtual void Read(bufferevent *be);

	// ◊¢≤·√¸¡Ó¥¶¿Ì∂‘œÛ£¨≤ª–Ë“™øº¬«œﬂ≥Ã∞≤»´£¨µ˜”√ ±Œ¥∑÷∑¢µΩœﬂ≥Ã
	void Reg(std::string, XFtpTask *call);


	XFtpServerCMD();
	~XFtpServerCMD();
private:
	std::map<std::string, XFtpTask*>calls;
	std::map<XFtpTask*, int>calls_del;
};

