#include <AVDictionary.h>
#include <AVFormatContext.h>
#include <AVError.h>
#include <FFmpegEnum.h>
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
	if (formatContext.open_input("./re.ts", nullptr, nullptr))
	{
		throw "打开输入失败";
	}
	if (formatContext.find_stream_info(nullptr) >= 0)
	{
		cout << formatContext()->nb_streams << endl;
		cout << formatContext()->bit_rate << endl;
	}
	cout << formatContext.get_duration_as_formatted_time_string() << endl;
	std::string err_str;
	err_str << FFmpeg::AVMediaType::AVMEDIA_TYPE_AUDIO;
	cout << err_str << endl;
	return 0;
}
