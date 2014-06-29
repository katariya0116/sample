#include <memory>
#include <iostream>
#include <array>
#include <algorithm>

const int map_x = 12;
const int map_y = 21;
const int map_block_num = map_x*map_y;

constexpr char answer(int _num)
{
	return static_cast<char>(static_cast<int>('a') + _num);
}

constexpr const char* map_block_chara(int _map)
{
	return (_map != 0 ? "* " : "  ");
}

constexpr bool check_map_wall(const int _idx, const int _map_x, const int _map_y)
{
	return (_idx % _map_x == 0 || _idx % _map_x == _map_x - 1 || _idx >= _map_x * (_map_y - 1));
}

int main()
{
	std::array<int, map_block_num> map; 
	std::string map_disp;
	for(int cnt = 0; cnt < map_block_num; ++cnt)
	{
		map[cnt] = check_map_wall(cnt, map_x, map_y) ? -1 : 0;
	}
	for(int cnt = 0; cnt < map_block_num; ++cnt)
	{
		map_disp += map_block_chara(map[cnt]);
		if(cnt % map_x == map_x - 1){ map_disp += "\n"; }
	}
	std::cout << map_disp << std::endl;

	auto as = 0;
	std::cin >> as;

	return 0;
}


