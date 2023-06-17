#pragma once

#include <Wraper.h>
#include <FFmpegEnum.h>
#include <string>
#include <sstream>
extern "C"
{
#define __STDC_CONSTANT_MACROS
#include <libavformat/avio.h>
#include <libavformat/avformat.h>
}

namespace FFmpeg
{
	class AVFormatContext : public Wraper<::AVFormatContext>
	{
	public:
#pragma region 生命周期
		AVFormatContext()
		{
			m_pWrapedObj = ::avformat_alloc_context();
		}
		AVFormatContext(::AVFormatContext *pFormatContext)
		{
			m_pWrapedObj = pFormatContext;
		}
		~AVFormatContext()
		{
			close_input();
			::avformat_free_context(m_pWrapedObj);
		}
#pragma endregion
#pragma region ffmpeg 中针对 AVFormatContext 的操作函数
		inline int open_input(const char *url, const ::AVInputFormat *fmt, ::AVDictionary **options)
		{
			return ::avformat_open_input(&m_pWrapedObj, url, fmt, options);
		}
		void close_input()
		{
			::avformat_close_input(&m_pWrapedObj);
		}
		inline int find_stream_info(::AVDictionary **options)
		{
			return ::avformat_find_stream_info(m_pWrapedObj, options);
		}
		int find_best_stream(AVMediaType type,
							 int wanted_stream_nb,
							 int related_stream,
							 const ::AVCodec **decoder_ret,
							 int flags)
		{
			return ::av_find_best_stream(m_pWrapedObj, type, wanted_stream_nb, related_stream, decoder_ret, flags);
		}
#pragma endregion
#pragma region 扩展方法
		inline std::string get_duration_as_formatted_time_string()
		{
			std::stringstream sstream;
			int64_t total_seconds = m_pWrapedObj->duration / AV_TIME_BASE;
			int64_t hour = total_seconds / 3600;
			total_seconds = total_seconds % 3600;
			int64_t mimute = total_seconds / 60;
			total_seconds = total_seconds % 60;
			int second = total_seconds;
			sstream << hour << "时" << mimute << "分" << second << "秒" << std::endl;
			std::string re_value;
			sstream >> re_value;
			return re_value;
		}
#pragma endregion
	};
}