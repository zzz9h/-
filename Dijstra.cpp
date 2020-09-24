#include <iostream>
using namespace std;
typedef struct {
	char nextPointName;
	int  distance;
}NEXT_POINT;

typedef struct {
	int		curVaule;
	int		expandFlag;
	char	name;
	int		linkNum;
	NEXT_POINT  nextPoint[5];
	char	route[10] = { 'A' };
}POINT;

POINT A = { 1000,0,'A' ,2,'B',5,'C',2 };
POINT B = { 1000,0,'B' ,2,'D',1,'E',6 };
POINT C = { 1000,0,'C' ,2,'D',6,'F',8 };
POINT D = { 1000,0,'D' ,2,'E',1,'F',2 };
POINT E = { 1000,0,'E' ,1,'G',7 };
POINT F = { 1000,0,'F' ,1,'G',3 };
POINT G = { 1000,0,'G' };


void Dijkstra(POINT* startPoint, POINT* endPoint, POINT* piontArray, int pointNum);
int main()
{
	POINT array[10] = { A,B,C,D,E,F,G };
	Dijkstra(&A, &G, array, 7);

	cout << "	最短路径为	" << G.route << endl << "	最短路径长度为	" << G.curVaule << endl;
	system("pause");
}

void Dijkstra(POINT* startPoint, POINT* endPoint, POINT* piontArray, int pointNum) {

	POINT unexpandPoint[20] = { 0 };

	int leftNum = pointNum;
	POINT expandPoint = *(startPoint);
	int temp = 0;

	for (int i = 0; i < pointNum; ++i) {
		unexpandPoint[i] = piontArray[i];
	}
	unexpandPoint[0].curVaule = 0;

	while (1) {
		expandPoint = unexpandPoint[0];
		for (int i = 0; i < leftNum; ++i) {
			if (expandPoint.curVaule > unexpandPoint[i].curVaule) {
				expandPoint = unexpandPoint[i];
				temp = i;
			}
		}
		if (expandPoint.name == endPoint->name) {
			*(endPoint) = expandPoint;

			break;
		}
		for (int i = 0; i < leftNum; ++i) {
			if (i > temp) {
				unexpandPoint[i - 1] = unexpandPoint[i];
			}
		}
		temp = 0;
		leftNum--;
		for (int i = 0; i < expandPoint.linkNum; ++i) {
			for (int j = 0; j < leftNum; ++j) {
				if (expandPoint.nextPoint[i].nextPointName == unexpandPoint[j].name) {
					if (unexpandPoint[j].curVaule > expandPoint.nextPoint[i].distance + expandPoint.curVaule) {
						unexpandPoint[j].curVaule = expandPoint.nextPoint[i].distance + expandPoint.curVaule;
					}
					if (unexpandPoint[j].curVaule > 1000) {
						unexpandPoint[j].curVaule -= 1000;
					}

					//路径更新
					for (int k = 0; k < 10; ++k) {
						unexpandPoint[j].route[k] = 0;
					}
					for (int k = 0; k < 10; ++k) {
						if (expandPoint.route[k] != 0) {
							unexpandPoint[j].route[k] = expandPoint.route[k];
						}
						else {
							unexpandPoint[j].route[k] = unexpandPoint[j].name;
							break;
						}
					}
				}
			}
		}

	}
}
