#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int init(void)
{
	return 0;
}

void global_check(void)
{

}

int auto_check(void)
{
	return 0;
}

int alarm(void)
{
	return 0;
}

int wait_for_user(void)
{
	return 0;
}

int start_countdown(void)
{
	return 0;
}

int let_water_in(void)
{
	return 0;
}

int do_wash(void)
{
	return 0;
}

int let_water_out(void)
{
	return 0;
}

int do_dry(void)
{
	return 0;
}

int finished(void)
{
	return 0;
}

int main(int argc, char *argv[])
{
	static uint8_t step = 1;

	//开机进行一些必要的初始化
	init();

	while(1)
	{
		//一些全局的事件检测可以放在这里，用于设置一些全局标志
		global_check();

		//状态机
		switch(step)
		{
			case 1: { //自检
				auto_check();

				if(自检通过) step = 2;
				else 		step = 18;
			}break;

			case 2: { //空闲
				wait_for_user();

				if(按下开始) step = 3;
			}break;
			case 3: { //倒计时
				start_countdown();

				if(倒计时结束) step = 4;
			}break;
			case 4: { //加水
				let_water_in();

				if(水加满了) step = 5;
			}break;
			case 5: {
				do_wash();

				if(清洗时间结束) step = 6;
			}break;
			case 6: { //放水
				let_water_out();

				if(水放完 && 只洗了一遍) 		step =  4;
				else if(水放完 && 洗了两遍) 	step = 7;
			}break;
			case 7: { //甩干
				do_dry();

				if(甩干时间结束) step = 8;
			}break;
			case 8: { //洗衣结束
				finished();

				step = 2;
			}break;
			case 18: {
				while(1) {
					//死循环，不再响应用户操作，并报警
					alarm();
				}
			}break;
			default: break;
		}
	}
}