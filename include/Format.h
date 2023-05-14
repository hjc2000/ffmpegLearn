#pragma once
#include <global.h>
#include <vector>

namespace FFmpeg
{
	class AVStream;
	class AVPacket;

	enum FormatMode
	{
		Open,
		Create,
	};

	class Format : public Wrapper<::AVFormatContext>
	{
	public: // 生命周期
		Format(char const *url, FormatMode mode);
		~Format();

	public: // 公共方法
		shared_ptr<FFmpeg::AVStream> GetBestStream(AVMediaType type);
		shared_ptr<FFmpeg::AVStream> GetStream(int index);
		void CreateNewStream(int numOfStream);
		void WriteHeader(void);
		void WriteTrailer(void);
		void Interleaved_Write_Frame(shared_ptr<FFmpeg::AVPacket> pkt);
		shared_ptr<FFmpeg::AVPacket> ReadFrame();
		void SeekFrame(double dstTime);
		void CopyAllStreamTo(Format &dstFormat);
		void CopyStreamTo(Format &dstFormat);

	public: // 属性访问器
		int get_NumOfStream(void);
		vector<shared_ptr<FFmpeg::AVStream>> &get_StreamList(void);

	private: // 私有方法
		void CreateOutputFormat(char const *url);
		void InitStreamVector(void);

		// 私有字段
	private:
		vector<shared_ptr<FFmpeg::AVStream>> _streams;
	};
}