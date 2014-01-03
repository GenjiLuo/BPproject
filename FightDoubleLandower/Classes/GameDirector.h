#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H
#include "player.h"
#include "LoadAllCardPic.h"
//��Ϸ���� ������ ��������Ϸ�Ŀ�ʼ ���� ���ƹ��� ��ʤ��
class Player; 

enum _result
{
	eLOSEALL = -2,
	eLOSE = -1,
	eTIE,
	eWIN,
	eWINALL 
};
struct _playerGameResult
{

	int ID;
	int staus;
};

class GameDirector
{
public:
	static GameDirector* getInstall();
	bool startGame();
	bool reStartGame();
	void resetCardSequeue();//ϴ��
	void dealCardSequeue();//����
	int getCardNum();//�ж���һ���ƴ���ǵ��� �� ���� ����
	int autoPlayAI(Player* p,int i);//�й�AI
	int getCardTypeNum(int start,int end,int type);//�ڷ�Χ��Ѱ������Ϊtype������
	void control();//��Ϸ���Ʒ���  ������Ϸ�Ľ���
	bool isDoubleLandowerType(){return isDoubleLandower;}
	void setGameStaus(int *,int &,bool& staus){ isGameOver = staus;}
	bool isGameStaus(){return isGameOver;}
		Player  *player;
private:
	GameDirector();
	int sort(int cardSequeue[],int start,int end);//�Եõ����ƽ������򣬲�������ҵ������Ϣ
	void setPlayerOneCard();
	bool isFree(int a);
	bool four;
	bool isNoOneWant(int a);
	void setPlayerCardsFree(int* card,int &num, bool &want,int k);
	void setPlayerTwoCards(int* card,int &num, bool &want);
	void setPlayerThreeCards(int* card,int &num, bool &want);
	void setPlayerFourCards(int* card,int &num, bool &want);
	void setPlayerFiveCards(int* card,int &num, bool &want);
	bool whichOneLarge(int a,int b);
	bool isLargest();
	void updatePlayerCard(Player* p);//��Ϸ�����ݻ�ȡ��ҵĳ�����Ϣ 
	bool judgeGameOver(Player* p,int num);	//��num�����P���˾�Ҫ�ж���Ϸ�Ƿ�Ӧ�ý���

	int cardSequeue[53];//ֻ���±�1��52
	int squeue;// 0 1 2 3 �ֱ��Ӧ���ĸ���ҳ���
	int cards[5];//�ϸ���ҵĳ���
	_playerGameResult playerGameResult[4];
	bool isDoubleLandower;
	bool isGameOver;
};
#endif