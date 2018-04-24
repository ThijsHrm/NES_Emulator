#pragma once
class Ram
{

public:
	Ram();
	~Ram();

private:
	const size_t ram_size = 2048;
	// mirrors of $0000-$07FF: $0800-$0FFF; $1000-$17FF; $1800-$1FFF;
	// 8 bit per byte

};

