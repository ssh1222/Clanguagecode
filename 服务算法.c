#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PCB
{
	char name[10];//进程名
	double high;//高级
	int ArriveTime;//到达时间
	int StartTime;//进程开始时间
	int FinishTime;//进程结束时间
	int ServiceTime;//服务时间
	double WholeTime;//周转时间
	double WeightWholeTime;//带权周转时间
	double AverageWT_FCFS;//平均周转时间
	double AverageWWT_FCFS;//带权平均周转时间	
}pcb;

typedef struct MEMORY
{
	pcb* array; 
	pcb* array1;
	int size;
}memory;

int time;//计时器
pcb w;
memory p;


//结构体初始化
void PCBInit()
{
	w.StartTime = 0;
	w.FinishTime = 0;
	w.WholeTime = 0;
	w.WeightWholeTime = 0;
	p.array = (pcb*)malloc(sizeof(pcb)* 10);
	p.size = 0;
}

enum
{
	END,
	FCFS,
	SJF,
	PSA,
	HRRN,
	RRFCFS,
};

int Choice()
{
	int choice = -1;
	printf("************************\n");
	printf("1.先来先服务算法\n");
	printf("2.短作业优先算法\n");
	printf("3.高优先级调度算法\n");
	printf("4.高响应比优先调度算法\n");
	printf("5.时间片轮转调度算法\n");
	printf("0.退出\n");
	printf("************************\n");
	printf("请输入你的选择：");
	scanf("%d", &choice);
	return choice;
}

void Run(pcb* p1)//运行未完成的进程
{	
	p1->StartTime = time;
	printf("\n时刻: %d,当前开始运行作业：%s\n\n", time, p1->name);
	time += p1->ServiceTime;
	p1->FinishTime = time;
	p1->WholeTime = p1->FinishTime - p1->ArriveTime;
	p1->WeightWholeTime = p1->WholeTime / p1->ServiceTime;
	p1->AverageWT_FCFS = p1->WholeTime / p.size;
	p1->AverageWWT_FCFS = p1->WeightWholeTime / p.size;
	printf("到达时间 开始时间 服务时间 完成时间 周转时间 带权周转时间\n");
	printf("%4d  %7d  %7d  %7d  %8.1lf  %9.2lf\n", p1->ArriveTime, 
		p1->StartTime, p1->ServiceTime, p1->FinishTime, p1->WholeTime, p1->WeightWholeTime);
	printf("\n平均周转时间 平均带权周转时间\n");
	printf("%9.2lf %11.2lf\n", p1->AverageWT_FCFS, p1->AverageWWT_FCFS);
}

//找到当前未完成的进程
void Loop()
{
	int i = 0;
	for (i = 0; i < p.size; ++i)
	{
		Run(&p.array[i]);
	}
}

//先来先服务算法
void FCFSGetInfo()
{
	printf("先来先服务FCFS算法\n");
	printf("\n进程个数：");
	scanf("%d", &p.size);
	for (int size = 0; size < p.size; ++size)
	{		
		printf("依次输入：\n进程名 到达时间 服务时间\n");
		scanf("%s\t%d\t%d", &p.array[size].name, &p.array[size].ArriveTime, 
			&p.array[size].ServiceTime);	
	}
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if (p.array[j].ArriveTime > p.array[j + 1].ArriveTime)
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}	
		}
		if (count == 0)
		{
			break;
		}	
	}
	time = p.array[0].ArriveTime;
}

//将第一个进程去除
void Print()
{
	for (int i = 0; i < p.size; ++i)
	{
		p.array[i] = p.array[i + 1];
	}
	--p.size;
}

//短作业优先算法
void SJFGetInfo()//获得进程信息并创建进程
{
	printf("短作业优先算法\n");
	printf("\n进程个数：");
	scanf("%d", &p.size);
	for (int size = 0; size < p.size; ++size)
	{
		printf("依次输入：\n进程名 到达时间 服务时间\n");
		scanf("%s\t%d\t%d", &p.array[size].name, &p.array[size].ArriveTime,
			&p.array[size].ServiceTime);
	}
	//根据到达时间给进程进行排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if (p.array[j].ArriveTime > p.array[j + 1].ArriveTime)
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	//根据服务时间给进程排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if ((p.array[j].ServiceTime > p.array[j + 1].ArriveTime)
				&&(p.array[j].ArriveTime == p.array[j + 1].ArriveTime))
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	time = p.array[0].ArriveTime;
	Run(&p.array[0]);
	//记录第一个进程的完成时间
	int time1 = p.array[0].ServiceTime;
	int time2 = p.array[0].ArriveTime;
	Print();
	int count = 0;
	for (int i = 0; i < p.size; ++i)
	{
		if (time1 >= p.array[i].ArriveTime)
		{
			++count;
		}
		if (count == 0)
		{
			time = time1 + p.array[0].ArriveTime;
			Run(&p.array[0]);
		}
		else
		{
			for (int i = 0; i < count; ++i)
			{
				int count1 = 0;
				for (int j = 0; j < count - i; ++j)
				{
					if (p.array[j].ServiceTime > p.array[j + 1].ServiceTime)
					{
						pcb tmp = p.array[j];
						p.array[j] = p.array[j + 1];
						p.array[j + 1] = tmp;
						count1 = 1;
					}
				}
				if (count1 == 0)
				{
					break;
				}
			}
			time = time1 + time2;
			Run(&p.array[0]);
		}
		time1 = p.array[0].ServiceTime;
		Print();
	}
}

//高优先级调度算法
void PSAGetInfo()
{
	printf("高优先级调度算法\n");
	printf("\n进程个数：");
	scanf("%d", &p.size);
	for (int size = 0; size < p.size; ++size)
	{
		printf("依次输入：\n进程名 到达时间 服务时间 优先级\n");
		scanf("%s\t%d\t%d\t%lf", &p.array[size].name, &p.array[size].ArriveTime,
			&p.array[size].ServiceTime, &p.array[size].high);
	}
	//根据到达时间给进程进行排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if (p.array[j].ArriveTime > p.array[j + 1].ArriveTime)
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	//根据优先级给进程排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if ((p.array[j].high < p.array[j + 1].high)
				&& (p.array[j].ArriveTime == p.array[j + 1].ArriveTime))
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	time = p.array[0].ArriveTime;
	Run(&p.array[0]);
	//记录第一个进程的完成时间
	int time1 = p.array[0].ServiceTime;
	int time2 = p.array[0].ArriveTime;
	Print();
	int count = 0;
	for (int i = 0; i < p.size; ++i)
	{
		if (time1 >= p.array[i].ArriveTime)
		{
			++count;
		}
		if (count == 0)
		{
			time =time1 + p.array[0].ArriveTime;
			Run(&p.array[0]);
		}
		else
		{
			for (int i = 0; i < count; ++i)
			{
				int count1= 0;
				for (int j = 0; j < count - i; ++j)
				{
					if (p.array[j].high < p.array[j + 1].high)
					{
						pcb tmp = p.array[j];
						p.array[j] = p.array[j + 1];
						p.array[j + 1] = tmp;
						count1 = 1;
					}
				}
				if (count1 == 0)
				{
					break;
				}
			}
			time = time1 + time2;
			Run(&p.array[0]);
		}
		time1 = p.array[0].ServiceTime;
		Print();
	}
}

//高响应比优先调度算法
void HRRNGetInfo()
{
	double time1 = 0;
	printf("高响应比优先调度算法\n");
	printf("\n进程个数：");
	scanf("%d", &p.size);
	for (int size = 0; size < p.size; ++size)
	{
		printf("依次输入：\n进程名 到达时间 服务时间\n");
		scanf("%s\t%d\t%d", &p.array[size].name, &p.array[size].ArriveTime,
			&p.array[size].ServiceTime);		
	}
	//根据达到时间给进程排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if (p.array[j].ArriveTime > p.array[j + 1].ArriveTime)
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	int times = 0;//记录所有的服务时间
	for (int i = 0; i < p.size; ++i)
	{
		times += p.array[i].ServiceTime;
	}
	//将第一个与第二个进行高响应比排序
	int p0time = (p.array[0].ArriveTime + p.array[0].ServiceTime)
		/ p.array[0].ServiceTime;
	int p1time = (p.array[1].ArriveTime + p.array[1].ServiceTime)
		/ p.array[1].ServiceTime;
	if (p0time > p1time)
	{
		pcb tmp = p.array[0];
		p.array[0] = p.array[1];
		p.array[1] = tmp;
	}
	//执行第一个程序
	time = p.array[0].ArriveTime;
	printf("\n高响应比：最大");
	Run(&p.array[0]);
	double time2 = p.array[0].ServiceTime;
	//根据高响应比给进程排序
	for (int i = 0; i < p.size; ++i)
	{
		Print();
		for (int i = 0; i < p.size; ++i)
		{
			//记录执行完成进程的时间
			time1 = time1 + time2+ p.array[i].ServiceTime;
			//计算当前剩余进程的响应比
			p.array[i].high = time1 / p.array[i].ServiceTime;
		}
		//根据响应比给进程排序
		for (int i = 0; i < p.size; ++i)
		{
			int count = 0;
			for (int j = 0; j < p.size - i - 1; ++j)
			{
				if (p.array[j].high < p.array[j + 1].high)
				{
					pcb tmp = p.array[j];
					p.array[j] = p.array[j + 1];
					p.array[j + 1] = tmp;
					count = 1;
				}
			}
			if (count == 0)
			{
				break;
			}
		}
		time2 = time2 + p.array[0].ServiceTime;
		time = p.array[0].ArriveTime;
		Run(&p.array[0]);
	}
}

//时间片轮转调度算 
void RRFCFSGetInfo()
{
	int num = 0;
	printf("时间片轮转算法\n");
	printf("时间片大小为：");
	scanf("%d", &num);
	printf("\n进程个数：");
	scanf("%d", &p.size);
	for (int size = 0; size < p.size; ++size)
	{
		printf("依次输入：\n进程名 到达时间 服务时间\n");
		scanf("%s\t%d\t%d", &p.array[size].name, &p.array[size].ArriveTime,
			&p.array[size].ServiceTime);
	}
	//根据到达时间给进程进行排序
	for (int i = 0; i < p.size; ++i)
	{
		int count = 0;
		for (int j = 0; j < p.size - i - 1; ++j)
		{
			if (p.array[j].ArriveTime > p.array[j + 1].ArriveTime)
			{
				pcb tmp = p.array[j];
				p.array[j] = p.array[j + 1];
				p.array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}

int main()
{
	while (1)
	{
		PCBInit();
		int choice = Choice();
		switch (choice){
		case FCFS:
			FCFSGetInfo();
			Loop();
			break;
		case SJF:
			SJFGetInfo();
			Loop();
			break;
		case PSA:
			PSAGetInfo();
			Loop();
			break;
		case HRRN:
			HRRNGetInfo();
			break;
		case RRFCFS:
			RRFCFSGetInfo();
			Loop();
			break;
		case END:
			printf("welcome bye\n");
			free(p.array);
			system("pause");
			return 0;
			break;
		default:
          printf("选择错误请从新输入！\n");
		}
	}
	free(p.array);
	system("pause");
	return 0;
}
