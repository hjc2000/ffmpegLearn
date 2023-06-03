#include <AVDictionary.h>
#include <iostream>
using namespace std;

int main(void)
{
	FFmpeg::AVDictionary dic;
	dic.av_dict_set("name", "hjc");
	cout << dic.av_dict_count() << endl;
	auto entry = dic.av_dict_get("name", nullptr);
	cout << entry->key << endl;
	cout << entry->value << endl;
	return 0;
}
