#include <FFmpeg.h>
#include <iostream>
using namespace FFmpeg;

int main(void)
{
	try
	{
		Format inputFormat = Format("./in.mp4", FFmpeg::FormatMode::Open);
		Format outputFormat = Format("./out.ts", FFmpeg::FormatMode::Create);
		outputFormat.CreateNewStream(2);
		auto streams = inputFormat.get_StreamList();
		streams[0]->set_DstIndex(1);
		streams[1]->set_DstIndex(0);
		// inputFormat.SeekFrame(100);
		inputFormat.CopyStreamTo(outputFormat);
	}
	catch (int errCode)
	{
		char buff[200];
		av_strerror(errCode, buff, sizeof(buff));
		std::cerr << buff << endl;
	}

	return 0;
}
