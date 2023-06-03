#pragma once
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

namespace FFmpeg
{
	/**
	 * @brief 字典操作的枚举类型
	 *
	 */
	enum AVDictionaryFlag
	{
		none = 0,

		match_case = 1, /**< Only get an entry with exact-case key match. Only relevant in av_dict_get(). */

		ignore_suffix = 2,	 /**< Return first entry in a dictionary whose first part corresponds to the search key,
												ignoring the suffix of the found key string. Only relevant in av_dict_get(). */
		dont_strdup_key = 4, /**< Take ownership of a key that's been
												  allocated with av_malloc() or another memory allocation function. */
		dont_strdup_val = 8, /**< Take ownership of a value that's been
												  allocated with av_malloc() or another memory allocation function. */
		dont_overwrite = 16, /**< Don't overwrite existing entries. */

		append = 32,  /**< If the entry already exists, append to it.  Note that no
										delimiter is added, the strings are simply concatenated. */
		multikey = 64 /**< Allow to store several equal keys in the dictionary */
	};

	typedef ::AVDictionaryEntry AVDictionaryEntry;

	class AVDictionary
	{
	public:
		~AVDictionary()
		{
			av_dict_free();
		}

#pragma region 对 ::AVDictionary 的实现
	public:
		/**
		 * @brief 获取字典中记录的条数
		 *
		 * @return int
		 */
		inline int av_dict_count()
		{
			return ::av_dict_count(m_dic);
		}

		/**
		 * @brief 向字典中写一条记录
		 *
		 * @param key
		 * @param value
		 * @param flags
		 * @return int
		 */
		inline int av_dict_set(const char *key, const char *value, AVDictionaryFlag flags = AVDictionaryFlag::none)
		{
			return ::av_dict_set(&m_dic, key, value, flags);
		}

		/**
		 * @brief 获取字典中的记录
		 *
		 * @param key
		 * @param previous_entry 指定上一条记录，如果指定，则从这里开始往后查找，
		 * 如果传入 nullprt 则从头开始查找
		 * @param flags
		 * @return FFmpeg::AVDictionaryEntry*
		 */
		FFmpeg::AVDictionaryEntry *av_dict_get(const char *key, const FFmpeg::AVDictionaryEntry *previous_entry, FFmpeg::AVDictionaryFlag flags = AVDictionaryFlag::none)
		{
			return ::av_dict_get(m_dic, key, previous_entry, flags);
		}

		/**
		 * @brief 释放字典使用的所有资源
		 *
		 */
		inline void av_dict_free()
		{
			::av_dict_free(&m_dic);
		}
#pragma endregion

	public:
		::AVDictionary *m_dic = nullptr;
	};
}