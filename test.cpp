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
		int err_code;
		FFmpeg::AVFormatContext formatContext;
		err_code = formatContext.open_input("./re.ts", nullptr, nullptr);
		if (err_code)
			throw err_code;
		err_code = formatContext.find_stream_info(nullptr);
		if (err_code < 0)
			throw err_code;
		cout << formatContext()->nb_streams << endl;
		cout << formatContext()->bit_rate << endl;
		cout << formatContext.get_duration_as_formatted_time_string() << endl;
		std::string media_type_str;
		media_type_str << FFmpeg::AVMediaType::AVMEDIA_TYPE_AUDIO;
		cout << media_type_str << endl;
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
