#ifndef PLAYER_H
#define PLAYER_H

#include "CCMenuItemCard.h"
enum Landower //��������Ϣ
{
	eNOLANDOWER = 0,	//ũ��
	eLANDOWER_ONE = 1,  //����A
	eLANDOWER_THREE = 3,//���3
	eDOUBLELANDOWER = 2 //˫��
};

enum cardStaus
{
	eDESK = false,
	eHAND = true
};
class Player
{
public:
	Player(int cardSequeue[],int start,int end);
	Player(){trusteeship = true;}
	void boundCardAndItem(int cardSequeue[],int start,int end,int position);
	void playOneHand(int cardOut[],int five);
	bool getIsTrusteeship(){return trusteeship;}
	void updateTrusteeshipStaus(){trusteeship = !trusteeship;}
	int getRemainCardNum(){return remainCardNum;}
	void setWantStaus(bool staus){want = staus;}
	bool getWantStaus(){return want;}
	void setCardZero(){memset(card,0,5);}
	CCMenuItemCard* getMenuItemCardByNum(int num){ return playCard[num];};//����0--12 ����
	void setCardToPlay(int a[],int num, bool wantStaus);
	int getCardNum(int i){ return card[i];}
	int getPosition(){return playerPosition;}
	bool judgePosition(){return isLandower;}
	int getNum(int i){return num[i];}
	bool hasNum(int i,int &j){return true;};//�Ƿ���ĳ����  
	
private:
	int remainCardNum;
	CCMenuItemCard* playCard[13]; 
	bool cardOnHand[13];
	int getCCMenuItemCardNum(int cardNum);
	int card[5];
	bool want;//
	bool trusteeship;//�й�
	int playerPosition;
	int num[13];// 1--52
	bool isLandower;
};

#endif