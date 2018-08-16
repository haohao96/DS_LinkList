#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define flag -1

#define maxsize 66

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct DLNode
{
	int data, freq;
	struct DLNode *prior, *next;
}DLNode, *DLinkList;

void InitLinkList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

LinkList From_Head_CreatList(LinkList &L)
{
	LNode *s;
	int x;
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != flag)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;

		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList From_Tail_CreatList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s = NULL, *r = L;
	int x;
	scanf_s("%d", &x);
	while (x != flag)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;

		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;


	return 0;
}

LinkList From_Tail_Creat_CircularList(LinkList &L)  //循环单链表 尾插法
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s = NULL, *r = L;
	int x;
	scanf_s("%d", &x);
	while (x != flag)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;

		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = L;


	return 0;
}

int From_Tail_Creat_Circular_DLinkList(DLinkList &DL)   //循环双链表尾插法 赋值
{
	DL = (DLNode *)malloc(sizeof(DLNode));
	DL->next = NULL;
	DLNode *r = DL;
	int x = 0;
	scanf_s("%d", &x);
	while (x != flag)
	{
		DLNode *s = (DLNode *)malloc(sizeof(DLNode));
		s->data = x;

		r->next = s;
		s->prior = r;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = DL;
	DL->prior = r;
	return 0;
}

int From_Tail_CreatDLinkList(DLinkList &DL)   //非循环双链表尾插法 赋值
{
	DL = (DLNode *)malloc(sizeof(DLNode));
	DL->next = NULL;
	DLNode *r = DL;
	int x = 0;
	scanf_s("%d", &x);
	while (x != flag)
	{
		DLNode *s = (DLNode *)malloc(sizeof(DLNode));
		s->data = x;
		s->freq = 0;

		r->next = s;
		s->prior = r;

		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;

	return 0;
}


//LinkList No_Head_Tail_CreatList(LinkList &L)
//{
//	//LNode *r = (LNode *)malloc(sizeof(LNode));
//
//	//L = NULL;
//
//	//int x;
//	//scanf_s("%d", &x);
//
//	////LNode *r = (LNode *)malloc(sizeof(LNode));
//	//LNode *r = L;
//
//	//while (x != 999)
//	//{
//	//	LNode *s = (LNode *)malloc(sizeof(LNode));
//	//	s->data = x;
//	//	s->next = NULL;
//
//	//	if (!L)
//	//	{
//	//		L = s;
//	//	}
//	//	else
//	//	{
//	//		s->next = r->next;
//	//		r->next = s;
//	//		r = s;
//	//	}
//	//	scanf_s("%d", &x);
//	//}
//
//
//
//
//	return L;
//}

LinkList No_Head_Tail_CreatList(LinkList &L)// 也可以让这个函数不带参数  这样就得 在函数里写：LinkList L=NULL;  效果一样的
{
	L = nullptr; //null也行
	int x;
	scanf_s("%d", &x);

	LNode *r = nullptr;
	LNode *s;
	r = (LNode *)malloc(sizeof(LNode));//这里如果没有把L给r，就要申请内存了。两种方式都可以的
									   //LNode *r=L, *s;//定义完结点一定要初始化，可以用一个点赋给它，如果没有能够赋值给它的，就要申请内存了，r = (LNode *)malloc(sizeof(LNode));
									   //   这句话是不对的：定义完 这个语句不可以少  不然就nullptr空指针  访问错误
	while (x != flag) //这就是个flag
	{

		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;

		if (!L)
		{
			L = s;
			r = L;
		}
		else
		{
			s->next = r->next;
			r->next = s;
			r = s;
		}
		scanf_s("%d", &x);
	}
	if (r)
		r->next = NULL;
	return L;
}


void Head_print(LinkList L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}

void Circular_DLinkList_Head_print(DLinkList DL)   //循环双链表打印
{
	DLNode *p = DL->next;
	while (p != DL)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}

void DLinkList_Head_print(DLinkList DL)   //非循环双链表打印
{
	DLNode *p = DL->next;
	while (p != NULL)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}

void Circular_LinkList_Head_print(LinkList L)   //循环单链表打印
{
	LNode *p = L->next;
	while (p != L)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}

void No_Head_print(LinkList L)
{
	LNode *p = L;
	while (p != NULL)
	{
		printf("%2d", p->data);
		p = p->next;
	}
}

void fun_1(LinkList &L, int x)
{
	LNode *p;

	if (L == NULL)
	{
		return;
	}
	if (L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		fun_1(L, x);
	}
	else
	{
		fun_1(L->next, x);
	}
}

void fun_2_1(LinkList &L, int x)
{
	LNode *p = L->next, *pre = L;
	while (p != NULL)
	{
		if (p->data == x)
		{
			LNode *q = p;

			pre->next = p->next;
			p = p->next;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void fun_2_2(LinkList &L, int x)
{
	LNode *p = L->next;
	L->next = NULL;
	LNode *r = L;
	while (p != NULL)
	{
		if (p->data == x)
		{
			LNode *q = p;
			p = p->next;
			free(q);
		}
		else
		{
			r->next = p;
			r = p;       // 1句      //这个地方1句和2句写反了  先写的2，
						 //然后问题是最后一轮的时候，p=null,
						 //然后r=p,r也被赋为了null。在执行r->next=NULL;的时候null的next怎么能被赋为null。
						 //所以出错
			p = p->next; // 2句

		}
	}
	r->next = NULL;
}

void fun_3_1(LinkList L)
{
	int a[99], i = 0;
	LNode *p = L->next;
	while (p != NULL)
	{

		a[i++] = p->data;
		p = p->next;
	}
	i -= 1;
	while (i >= 0)
	{
		printf("%3d", a[i--]);
	}
	printf("\n");
}

void fun_3_2(LinkList L) //递归的写法
{
	if (L->next != NULL)
	{
		fun_3_2(L->next);
		printf("%4d", L->next->data);
	}
}

//void fun_3_3(LinkList L) //栈的写法
//{
//
//}

void fun_3_4(LinkList L) //改变链表方向
{
	LNode *pre, *p = L->next, *r = p->next;
	p->next = NULL;
	while (r != NULL)
	{

		pre = p;
		p = r;
		r = r->next;

		p->next = pre;
	}
	L->next = p;

	while (p != NULL)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}



void fun_4(LinkList &L)
{
	LNode *pre = L, *p = L->next, *minpre, *minp;
	minp = p;
	minpre = pre;
	while (p != NULL)
	{
		if (p->data<minp->data)
		{
			minp = p;
			minpre = pre;
			pre = p;
			p = p->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	LNode *q = minp;
	minpre->next = minp->next;
	free(q);
}

LinkList fun_5_1(LinkList &L)
{
	LNode *p = L->next, *r;
	L->next = NULL;

	while (p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}

	return L;
}

LinkList fun_5_2(LinkList L)
{
	LNode *pre = L, *p = L->next, *r = p->next;
	p->next = NULL;

	while (r != NULL)
	{
		pre = p;
		p = r;
		r = r->next;

		p->next = pre;
	}
	L->next = p;
	return L;
}

LinkList fun_6(LinkList &L)  //还有一种方法：空间换时间 用nlogn的排序先排好
{
	LNode *p = L->next, *pre = L, *r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next; //保存p后继
		while (pre->next != NULL && pre->next->data<p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;

		p = r;
	}

	return L;
}

LinkList fun_7(LinkList &L, int a, int b)
{
	LNode *pre = L, *p = L->next; //用r保存p后继也不行，因为释放节点，还是会断掉。
	while (p != NULL)
	{

		if (p->data > a&&p->data < b)
		{
			LNode *q = p;

			pre->next = p->next;//
			free(q);


			p = pre->next;   //p往后走 没写对  所以这个不能写p=p->next;释放之后 0xdddddddd

		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return L;
}

int  fun_8()  //这样写不对，这样不是一个点，只是它们的值相等，但是不了解它们类型   它们的地址也不等  不深入了解 做不出来
{
	LinkList L1, L2;


	int i = 0, j = 0;

	From_Tail_CreatList(L1);
	Head_print(L1);
	printf("\n");
	From_Tail_CreatList(L2);
	Head_print(L2);
	printf("\n");

	LNode *l1 = L1->next, *l2 = L2->next;

	while (l1 != NULL)
	{
		i++;
		l1 = l1->next;
	}
	while (l2 != NULL)
	{
		j++;
		l2 = l2->next;
	}

	int k = i > j ? i - j : j - i;

	l1 = L1->next;//重新赋值 从头开始
	l2 = L2->next;

	if (i>j)
	{
		int k = i - j;
		while (k>0)
		{
			l1 = l1->next;
			k--;
		}
	}
	else if (j>i)
	{
		int k = j - i;
		while (k>0)
		{
			l2 = l2->next;
		}
	}
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->data == l2->data)
		{
			return l1->data;
		}
		else
		{
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	return l1->data;
}

//LNode fun_9()      //这是错误的，但是很典型。
//{
//	LinkList L;
//	From_Head_CreatList(L);
//	Head_print(L);
//	printf("\n");
//	LNode *p=L->next, *pre=L,*minp,*minpre;
//	minp=p;
//	minpre = pre;
//	p = p->next;
//	while (L->next!=NULL)
//	{
//		while (p!=nullptr)
//		{
//			if (minp->data>p->data)
//			{
//				minp = p;
//				minpre = pre;
//				if (p->next)
//				{
//					pre = p;
//					p = p->next;
//				}
//				
//			}
//			else if(p->next)
//			{	
//				pre = p;
//				p = p->next;
//			}			
//		}
//		pre->next = p->next;
//		LNode *q = p;
//		free(q);
//
//		return *p;
//
//		minp=p = L->next;
//		minpre=pre = L;
//		
//	}
//
//
//
//	return *p;
//}

void fun_9()
{
	LinkList L;
	From_Head_CreatList(L);
	Head_print(L);
	printf("\n");

	LNode *p = L->next, *pre = L, *minp;
	while (L->next != NULL)
	{
		p = L->next; //新一轮查找重新赋值
		pre = L;     //新一轮查找重新赋值

		while (p->next != NULL)
		{
			if (pre->next->data>p->next->data)
				pre = p;
			p = p->next;
		}
		printf("%4d", *p);

		pre->next = p->next;
		free(p);
	}
}

void fun_10()
{
	LinkList La, Lb;
	From_Tail_CreatList(La);
	Head_print(La);
	printf("\n");
	InitLinkList(Lb);
	int i = 1;
	LNode *p = La->next, *rb = Lb, *ra = La;
	La->next = NULL;
	while (p != NULL)
	{

		if (i % 2 == 0)
		{
			rb->next = p;
			i++;
			rb = p;
		}
		else
		{
			ra->next = p;
			i++;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;

	Head_print(La);
	printf("\n");
	Head_print(Lb);

}

void fun_11()
{
	LinkList  Lc;
	From_Tail_CreatList(Lc);
	Head_print(Lc);
	printf("\n");

	typedef struct
	{
		int data[maxsize];
		int length;
	}Sqlist;

	Sqlist La, Lb;

	LNode *p = Lc->next;

	int i = 0, j = 0;

	while (p != NULL)
	{

		La.data[i++] = p->data;
		p = p->next;

		Lb.data[j++] = p->data;
		p = p->next;
	}

	//i -= 1;
	//j -= 1;

	while (i>0)
	{
		printf("%4d", La.data[--i]);
	}
	printf("\n");

	while (j > 0)
	{
		printf("%4d", Lb.data[--j]);
	}
	printf("\n");
}

void fun_12_1()
{
	LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");

	LNode *p = L->next, *vernier = p;
	p = p->next;
	while (p != NULL)
	{
		if (vernier->data == p->data)
		{
			LNode *r = p->next;
			vernier->next = p->next;
			p = r;
		}
		else
		{
			vernier = p;
			p = p->next;
		}
	}
	Head_print(L);
	printf("\n");


}

void fun_12_2()
{
	LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");

	LNode *p = L->next, *vernier = p, *r = p;
	p = p->next;

	while (p != NULL)
	{

		if (p->data != vernier->data)
		{

			LNode *q = p;
			vernier->next = q;

			vernier = p; //更新
			p = p->next; //更新
		}
		else
		{
			p = p->next;
		}
		if (p)
		{
			r = p;
		}
		if (r->data == vernier->data)
		{
			r = vernier;
		}

	}
	r->next = NULL;
	Head_print(L);
	printf("\n");
}

void fun_13()
{
	LinkList La, Lb;
	From_Tail_CreatList(La);
	Head_print(La);
	printf("\n");
	From_Tail_CreatList(Lb);
	Head_print(Lb);
	printf("\n");

	LNode *la = La->next, *lb = Lb->next, *r = la;
	La->next = NULL;
	while (la != NULL && lb != NULL)
	{
		if (la->data <= lb->data)
		{
			r = la->next;
			la->next = La->next;
			La->next = la;

			la = r;
		}
		else
		{
			r = lb->next;
			lb->next = Lb->next;
			Lb->next = lb;

			lb = r;
		}
	}

	if (la)
	{
		lb = la;
	}

	while (lb)
	{
		r = lb->next;
		lb->next = La->next;
		La->next = lb;

		lb = r;
	}
	free(Lb);
	Head_print(La);
	printf("\n");

}

void fun_14()
{
	LinkList La, Lb, Lc;
	From_Tail_CreatList(La);
	Head_print(La);
	printf("\n");
	From_Tail_CreatList(Lb);
	Head_print(Lb);
	printf("\n");

	Lc = (LNode *)malloc(sizeof(LNode));

	LNode *pa = La->next, *pb = Lb->next, *r = Lc;

	while (pa&&pb)
	{
		if (pa->data<pb->data)
		{
			pa = pa->next;
		}
		else if (pa->data>pb->data)
		{
			pb = pb->next;
		}
		else
		{
			LNode *s = pa;

			r->next = s;
			r = s;

			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
	Head_print(Lc);
	printf("\n");
}

void fun_15()
{
	LinkList La, Lb;
	From_Tail_CreatList(La);
	Head_print(La);
	printf("\n");
	From_Tail_CreatList(Lb);
	Head_print(Lb);
	printf("\n");

	LNode *pa = La->next, *pb = Lb->next, *q, *r = La;

	while (pa&&pb)
	{
		if (pa->data == pb->data)
		{
			r->next = pa;
			r = pa;
			q = pb;

			pa = pa->next;
			pb = pb->next;

			free(q);
		}
		else if (pa->data<pb->data)
		{
			q = pa;
			pa = pa->next;

			free(q);
		}
		else
		{
			q = pb;
			pb = pb->next;

			free(q);
		}
	}
	r->next = NULL;

	while (pa)
	{
		q = pa->next;
		free(pa);
		pa = q;

	}
	while (pb)
	{
		q = pb->next;
		free(pb);
		pb = q;

	}
	Head_print(La);
	printf("\n");


}

bool fun_16()
{
	int i = 0;
	LinkList La, Lb;
	From_Tail_CreatList(La);
	Head_print(La);
	printf("\n");
	From_Tail_CreatList(Lb);
	Head_print(Lb);
	printf("\n");

	LNode *pa = La->next, *pb = Lb->next;

	while (pb&&pa)
	{
		if (pa->data == pb->data)
		{
			pa = pa->next;
			pb = pb->next;
			i = -1;
		}
		else
		{
			if (i == -1)
			{
				return false;
				break;
			}
			pa = pa->next;
		}
	}
	if (pb == NULL)
	{
		return true;
	}
}

bool fun_17_1()
{
	DLinkList L;
	From_Tail_CreatDLinkList(L);
	Circular_DLinkList_Head_print(L);
	printf("\n");

	int listlen = 0, a[maxsize];

	DLNode *p = L->next;
	while (p)
	{
		p = p->next;
		listlen++;
	}
	p = L->next;

	//listlen -= 1;

	int i = 0;
	int len = listlen / 2;
	while (len > 0)
	{

		a[i++] = p->data;
		p = p->next;
		len--;
	}
	i -= 1;
	if (listlen % 2 == 1)
	{
		p = p->next;
	}
	while (p != NULL)
	{
		if (a[i--] == p->data)
		{
			p = p->next;
		}
		else
		{
			return false;
			break;
		}
	}

	return true;
}

bool fun_17_2()
{
	DLinkList L;
	From_Tail_CreatDLinkList(L);
	Circular_DLinkList_Head_print(L);
	printf("\n");

	DLNode *p = L->next, *q = L->prior;
	while (p != q && q->next != p)
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->prior;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void fun_18()
{
	LinkList(La);
	LinkList(Lb);
	From_Tail_Creat_CircularList(La);
	Circular_LinkList_Head_print(La);
	printf("\n");
	From_Tail_Creat_CircularList(Lb);
	Circular_LinkList_Head_print(Lb);
	printf("\n");

	LNode *pa = La->next, *pb = Lb->next, *ra, *rb;
	ra = (LNode *)malloc(sizeof(LNode));
	rb = (LNode *)malloc(sizeof(LNode));
	while (pa != La)
	{
		ra = pa;
		pa = pa->next;
	}

	while (pb != Lb)
	{
		rb = pb;
		pb = pb->next;
	}


	ra->next = Lb->next;
	rb->next = La;

	pa = La->next;
	Circular_LinkList_Head_print(La);
	printf("\n");

}

void fun_19()
{
	LinkList L;
	From_Tail_Creat_CircularList(L);
	Circular_LinkList_Head_print(L);
	printf("\n");

	LNode *pre = L, *p = L->next, *minp = L->next, *minpre = L;
	//p = p->next;
	while (L->next != L)
	{
		pre = L;
		p = L->next;
		minp = L->next;
		minpre = L;
		while (p != L)
		{
			if (p->data<minp->data)
			{
				minpre = pre;
				minp = p;
			}
			pre = p;
			p = p->next;
		}
		printf("%4d", minp->data);
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}

void fun_20_1()      //很笨的方法  但毕竟是自己写的  不舍得删
{
	DLinkList DL;
	From_Tail_CreatDLinkList(DL);
	DLinkList_Head_print(DL);
	printf("\n");

	int x = 0;
	scanf_s("%d", &x);

	DLNode *p = DL->next, *pre = DL;
	while (x != flag)
	{
		p = DL->next;
		while (p != NULL)
		{
			if (p->data == x)
			{
				p->freq++;

				pre = DL;
				while (pre->next->next != NULL)
				{

					if (p->freq < pre->next->freq&&p->freq >= pre->next->next->freq)

					{
						if (p->next != NULL)
						{
							p->next->prior = p->prior;//摘下
							p->prior->next = p->next; //摘下
						}
						else
						{
							p->prior->next = NULL;//摘下
						}
						p->next = pre->next->next;
						pre->next->next->prior = p;
						p->prior = pre->next;
						pre->next->next = p;
					}
					else if (DL->next->freq == 0)
					{

						if (p->next != NULL)
						{
							p->next->prior = p->prior;//摘下
							p->prior->next = p->next; //摘下
						}
						else
						{
							p->prior->next = NULL;//摘下
						}

						p->next = pre->next;
						pre->next->prior = p;
						p->prior = pre;
						pre->next = p;

						break;
					}
					else
					{
						if (p->freq == DL->next->freq)
						{
							break;
						}
					}
					pre = pre->next;
				}

			}
			p = p->next;
		}
		scanf_s("%d", &x);
	}
	DLinkList_Head_print(DL);
	printf("\n");
}

void fun_20_2()   //有问题  如果x是表的最后一个点  就不行了
{
	DLinkList DL;
	From_Tail_CreatDLinkList(DL);
	DLinkList_Head_print(DL);
	printf("\n");

	int x = 0;
	scanf_s("%d", &x);

	DLNode *p = DL->next, *q;

	while (x != flag)
	{

		while (p&&p->data != x)
			p = p->next;

		if (!p)
		{
			printf("木牛\n");
		}
		else
		{
			p->freq++;
			p->next->prior = p->prior;
			p->prior->next = p->next;

			q = p->prior;
			while (q != DL && q->freq <= p->freq)
			{
				q = q->prior;
			}
			p->next = q->next;
			q->next->prior = p;
			p->prior = q;
			q->next = p;
		}
		scanf_s("%d", &x);
	}
	DLinkList_Head_print(DL);
	printf("\n");


}

void fun_21()   //完美
{
	LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");


	int k;
	printf("Please input k:\n");
	scanf_s("%d", &k);

	while (k != flag)
	{
		int len = 0;
		LNode *p = L->next, *required = p;

		while (p != NULL)
		{
			p = p->next;
			len++;
		}

		if (len<k)
		{
			printf("木牛\n");
			printf("Please input k:\n");
			scanf_s("%d", &k);
			continue;
		}

		p = L->next;
		while (--k>0)
		{
			p = p->next;
		}

		while (p->next != NULL)
		{
			p = p->next;
			required = required->next;
		}
		printf("Result:\n");
		printf("%d\n", required->data);

		printf("Please input k:\n");
		scanf_s("%d", &k);
	}


}

void fun_22()
{
	//太简单 跳过
}

void fun_23_1()   //自己的思路  自己敲的  完美
{
	LinkList L;
	From_Tail_CreatList(L);
	printf("\n");

	LNode *p = L->next, *r = NULL, *pre = L;

	int x = 0;
	printf("Please input number:\n");
	scanf_s("%d", &x);

	while (x != flag)
	{
		int f = 0;
		p = L->next;
		while (p != NULL)
		{
			r = p->next;
			if (x != abs(p->data))
			{
				pre = p;
				p = r;
				continue;
			}
			else if (f == 0)
			{
				f = 1;
			}
			else
			{
				LNode *f = p;
				pre->next = p->next;
				free(f);

				p = r;
				continue;
			}
			pre = p;
			p = r;
		}
		Head_print(L);
		printf("\n");

		printf("Please input number:\n");
		scanf_s("%d", &x);
	}

}

void fun_23_2()
{
	LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");

	LNode *p = L->next, *r = NULL;
	int len = 0;

	while (p != NULL)
	{
		p = p->next;

		len++;
	}

	int *q = (int *)malloc(sizeof(int)*(len + 1));
	int rlen = len + 1;
	while (rlen-->0)
	{
		*(q + rlen) = 0;
	}

	p = L;
	while (p->next != NULL)
	{
		int m = p->next->data>0 ? p->next->data : -p->next->data;

		if (*(q + m) == 0)
		{
			*(q + m) = 1;
			p = p->next;
		}
		else
		{
			r = p->next;
			p->next = r->next;
			free(r);
		}
	}
	free(q);
	Head_print(L);
	printf("\n");
}

LinkList Merge(LinkList L1, LinkList L2)
{
	LNode *p1 = L1->next, *p2 = L2->next;

	L1->next = NULL;
	LNode *r = L1;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			r->next = p1;
			r = p1;

			p1 = p1->next;
		}
		else
		{
			r->next = p2;
			r = p2;

			p2 = p2->next;
		}
	}
	if (p1)
	{
		r->next = p1;
	}
	else
	{
		r->next = p2;
	}

	return L1;
}

int main()
{
	/*第一题：
	LinkList L;
	No_Head_Tail_CreatList(L);
	No_Head_print(L);
	printf("\n");
	fun_1(L, 1);
	No_Head_print(L);
	fun_1(L, 3);
	printf("\n");
	No_Head_print(L);*/

	//第二题：
	/*LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");
	fun_2_1(L,1);
	fun_2_1(L, 8);
	Head_print(L);
	printf("\n");
	fun_2_2(L, 1);
	fun_2_2(L, 8);
	Head_print(L);*/

	//第三题：
	//LinkList L;
	//From_Tail_CreatList(L);
	//Head_print(L);
	//printf("\n");
	//fun_3_4(L);
	//printf("\n");

	//第四题：
	/*LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");
	fun_4(L);
	Head_print(L);*/

	/*第五题：
	LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");
	fun_5_2(L);
	Head_print(L);*/

	//第六题：
	/*LinkList L;
	From_Head_CreatList(L);
	Head_print(L);
	printf("\n");
	fun_6(L);
	Head_print(L);*/

	//第七题：
	/*LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");
	fun_7(L,1,6);
	Head_print(L);*/

	//第八题：
	/*printf("%d\n", fun_8());*/

	//第九题：
	/*fun_9();*/

	//第十题：
	/*fun_10();*/

	//第十一题：
	/*fun_11()*/;


	//第十二题：
	//fun_12_2();

	//第十三题：
	//fun_13();

	//第十四题：
	/*fun_14();*/

	//第十五题：
	/*fun_15();*/

	//第十六题：
	//printf("%d\n",fun_16());

	//第十七题：
	/*printf("%d\n", fun_17_2());*/


	//第十八题：
	//fun_18();

	//第十九题：
	/*fun_19();*/

	//第二十题：
	/*fun_20_2();*/

	//第二十一题：
	/*fun_21();*/

	//第二十二题：
	//fun_22();

	//第二十三题：
	//fun_23_1();

	/*LinkList L;
	From_Tail_CreatList(L);
	Head_print(L);
	printf("\n");*/

	LinkList L1, L2;
	From_Tail_CreatList(L1);
	Head_print(L1);
	printf("\n");
	From_Tail_CreatList(L2);
	Head_print(L2);
	printf("\n");

	L1 = Merge(L1, L2);
	Head_print(L1);
	printf("\n");

	return 0;
	/*backup to github*/
}
