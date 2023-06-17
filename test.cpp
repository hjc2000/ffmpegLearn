#include <AVDictionary.h>
#include <AVFormatContext.h>
#include <iostream>
#include <fstream>
#include <string>
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

using std::cout;
using std::endl;
using std::fstream;
using std::ios_base;
using std::string;

int main(void)
{
	FFmpeg::AVFormatContext formatContext;
	if (avformat_open_input(formatContext, "./re.ts", nullptr, nullptr))
	{
		throw "打开输入失败";
	}
	if (avformat_find_stream_info(formatContext, nullptr) >= 0)
	{
		cout << formatContext()->nb_streams << endl;
	}
	return 0;
}
