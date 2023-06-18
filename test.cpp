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
	try
	{
		FFmpeg::AVFormatContext formatContext;
		formatContext.open_input("./re.ts");
		formatContext.find_stream_info();
		int stream_index = formatContext.find_best_stream(FFmpeg::AVMediaType::AVMEDIA_TYPE_AUDIO);
		cout << stream_index << endl;
		stream_index = formatContext.find_best_stream(FFmpeg::AVMediaType::AVMEDIA_TYPE_VIDEO);
		cout << stream_index << endl;
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
