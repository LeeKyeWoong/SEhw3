#pragma once
#include <string>

using namespace std;


class Ticket {
	//Class : Ticket
	//Description : Ticket�� ������ ��Ÿ���� entity class
	//Created : 2019/05/28
	//Author : ȫ����
	

private:
	string tid; //Ƽ�� ID
	string sid; //seller�� ID
	string homeTeam; //Ȩ��
	string awayTeam; //������� 
	int price; //Ƽ���� ����
	string gameDatenTime; //���� ���۳�¥�� �ð�
	string registerTicketDate; //Ƽ�� ��� ��¥ -> ������� 1���� ���� Ƽ�� �񱳸� ����
	string seatNum; //Ƽ���� �¼�
	bool isSold; //�ȷȴ����� ����
	string ticketType; //Ƽ���� Ÿ�� -> �Ϲ����� �������
	bool isLimitedTimeAuction; //Ƽ���� ��ŷ� �ѱ�������� ����



public:
	Ticket(); //������
	void addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction ); //Ƽ�� ����
	//��¥ �ð� ���� : 2019:05:22:12:00
	//void removeTicket();

	bool getReservable(); //Ƽ���� ����Ǿ������� ���� Ȯ��
	void setReservable(bool isSold);
	string getSellerId(); //�Ǹ����� ���̵� ��������
	string getTicketId(); //Ƽ�� ���̵� �������� -> Ƽ�Ͽ� �ο��� �����ȣ�� Ī�Ѵ�.
	string getHomeTeam(); //Ȩ�� ��������
	string getAwayTeam();
	int getTicketPrice();
	//int getAuctionTicketPrice(); ->���� �ʿ��Ѱ�... �ֳ��ϸ� ���Ƽ���� �׻� �ݰ����� �����ϱ� �����̴�.
	string getTicketRegisterDate();


};