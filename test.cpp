#include <AVDictionary.h>
#include <AVFormatContext.h>
#include <AVError.h>
#include <AVUtil.h>
#include <AVStream.h>
#include <AVPacket.h>
extern "C"
{
#define __STDC_CONSTANT_MACROS
#include <libavutil/log.h>
#include <libavutil/error.h>
#include <libavutil/avutil.h>
#include <libavformat/avio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
}
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::fstream;
using std::ios_base;
using std::string;
#include <memory>
using std::shared_ptr;

class Base
{
public:
	Base()
	{
		cout << "Base 无参构造函数" << endl;
	}
	virtual ~Base()
	{
		cout << "Base 类析构函数" << endl;
	}
};

class Test : public Base
{
public:
	Test()
	{
		cout << "Test 无参构造函数" << endl;
	}
	~Test()
	{
		cout << "Test 类析构函数" << endl;
	}
};

int main(void)
{
	try
	{
		shared_ptr<int> spi = shared_ptr<int>{new int{0}};
		spi = spi;
		cout << spi.use_count() << endl;
		return 0;
	}
	catch (int err_code)
	{
		std::cerr << FFmpeg::error_code_to_str(err_code) << endl;
	}
	catch (const char *str)
	{
		std::cerr << str << endl;
	}
}
