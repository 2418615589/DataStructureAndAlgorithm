//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<iomanip>
using namespace std;
const int MaxL = 5;
/*
  ͼ���ڽӾ����ʾ
  vertexType Ϊ���������
  MGraphͼ���ڽӾ����ʾ
*/
struct VertexType     
{
	int no;
	char data[MaxL];     
};
template<typename T>
struct MGraph      
{
	T edges[MaxL][MaxL];
	int n, e;      //n is vertex,e is edge
	VertexType vexs[MaxL];   
};
/*
  ͼ���ڽӱ�Ĵ洢����
  VNode Ϊ��ͷ�Ľ��
  ArcNode Ϊ�߽��
*/
template<typename T>
struct ArcNode
{
	int adjvex;				//�ߵĽ��
	ArcNode<T> *nextarc;    //ָ����һ���ߵ�ָ�� 
	T weight;			    //Ȩֵ
};
template<typename T>
struct VNode
{
	char data[MaxL];         //������Ϣ
	ArcNode<T> *firstarc;    //ָ���һ���ߵ����ڶ���
};
template<typename T>
struct ALGraph
{
	VNode<T> adjlist[MaxL];
	int n, e;
};
/*
  implement class Graph
*/
template<typename T> class Graph
{
private:
	MGraph<T> g;             //ͼ���ڽӾ���
	ALGraph<T> *G;           //ͼ���ڽӱ�
public:
	Graph() { G =nullptr; }
	void CreateMGraph(T a[][MaxL], int n, int e);    //ͨ�������鴴���ڽӾ���
	void DispMGraph();
	void CreateALGraph(T a[][MaxL], int n, int e);
	void DispALGraph();
};
//
template<typename T>
void Graph<T>::CreateMGraph(T a[][MaxL], int n, int e) {
	g.n = n;
	g.e = e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g.edges[i][j] = a[i][j];
	}
}
//
template<typename T>
void Graph<T>::DispMGraph() {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++)
			cout << setw(4) << g.edges[i][j];
		cout << endl;
	}
}
//
template<typename T>
void Graph<T>::CreateALGraph(T a[][MaxL], int n, int e) {
	G = new ALGraph<T>();
	G->n = n; G->e = e;
	ArcNode<T> *p;
	for (int i = 0; i < n; i++)			  //��ʼ����ͷ
		G->adjlist[i].firstarc = nullptr;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] != 0 && a[i][j] != -1) {      //-1��ʾ���߲����ڣ�ȨֵΪ����
				p = new ArcNode<T>();     //�����ڵ�
				p->adjvex = j;
				p->weight = a[i][j];
				p->nextarc = G->adjlist[i].firstarc;    //ͷ�巨
				G->adjlist[i].firstarc = p;

			}
		}
	}
}
//
template<typename T>
void Graph<T>::DispALGraph() {
	ArcNode<T> *p;
	for (int i = 0; i < G->n; i++) {
		cout << "[" << i << "]";
		p = G->adjlist[i].firstarc;
		if (p) cout << "->";
		while (p) {
			cout << " " << p->adjvex << "(" << p->weight << ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}
#endif // !GRAPH_H

