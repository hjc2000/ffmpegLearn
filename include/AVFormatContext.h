#pragma once
#include <Wraper.h>
#include <AVUtil.h>
#include <AVPacket.h>
extern "C"
{
#define __STDC_CONSTANT_MACROS
#include <libavformat/avio.h>
#include <libavformat/avformat.h>
}
#include <string>
#include <sstream>

namespace FFmpeg
{
	class AVFormatContext : public Wraper<::AVFormatContext>
	{
#pragma region 生命周期
	public:
		AVFormatContext()
		{
			m_pWrapedObj = ::avformat_alloc_context();
		}
		AVFormatContext(::AVFormatContext *pFormatContext)
		{
			m_pWrapedObj = pFormatContext;
		}
		AVFormatContext(::AVFormatContext &ref_FormatContext)
		{
			m_pWrapedObj = &ref_FormatContext;
		}
		~AVFormatContext()
		{
			close_input();
			::avformat_free_context(m_pWrapedObj);
		}
#pragma endregion

#pragma region ffmpeg 中针对 AVFormatContext 的操作函数
	public:
		inline void open_input(const char *url, const ::AVInputFormat *fmt = nullptr, ::AVDictionary **options = nullptr)
		{
			int result = ::avformat_open_input(&m_pWrapedObj, url, fmt, options);
			if (result < 0)
				throw result;
		}

		void close_input()
		{
			::avformat_close_input(&m_pWrapedObj);
		}

		inline void find_stream_info(::AVDictionary **options = nullptr)
		{
			int result = ::avformat_find_stream_info(m_pWrapedObj, options);
			if (result < 0)
				throw result;
		}

		/**
		 * @brief 找出最好的流
		 *
		 * @param type
		 * @param wanted_stream_nb
		 * @param related_stream
		 * @param decoder_ret
		 * @param flags
		 * @return int
		 */
		int find_best_stream(AVMediaType type,
							 int wanted_stream_nb = -1,
							 int related_stream = -1,
							 const ::AVCodec **decoder_ret = nullptr,
							 int flags = 0)
		{
			int result = ::av_find_best_stream(m_pWrapedObj, type, wanted_stream_nb, related_stream, decoder_ret, flags);
			if (result < 0)
				throw result;
			else
				return result;
		}

		void read_frame(FFmpeg::AVPacket &ref_packet)
		{
			int result = ::av_read_frame(m_pWrapedObj, ref_packet);
			if (result < 0)
				throw result;
		}
#pragma endregion

#pragma region 扩展方法
	public:
		/**
		 * @brief 获取视频时长
		 *
		 * @return std::string 返回结果是一个字符串，里面储存着格式化过的时间。格式为
		 * 时:分:秒
		 */
		inline std::string get_duration_as_formatted_time_string()
		{
			std::stringstream sstream;
			// 获取视频总的秒数
			int64_t total_seconds = m_pWrapedObj->duration / AV_TIME_BASE;
			// 取出秒
			int second = total_seconds % 60;
			// 扣除秒位后总的分钟数
			uint64_t total_minutes = total_seconds / 60;
			// 取出分钟
			int minute = total_minutes % 60;
			// 扣除分钟后总的小时数
			uint64_t total_hours = total_minutes / 60;
			sstream << total_hours << "时" << minute << "分" << second << "秒" << std::endl;
			std::string re_value;
			sstream >> re_value;
			return re_value;
		}
#pragma endregion
	};
}