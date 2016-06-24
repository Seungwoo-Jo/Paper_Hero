#include "CGlobal.h"

bool CGlobal::RunAfterTimeElapsed(double time)
{
	DWORD curTime = GetNowCount();					// ���� �ð�
	double timeDelta = (curTime - lastTime)*0.001f;	// timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	timeElapsed += timeDelta; 
	bool result = false;

	if( timeElapsed >= time )	// �帥�ð��� time �̻��̸� true ��ȯ
	{
		timeElapsed = 0.0f;
		result = true;
	}
	lastTime = curTime;

	return result;
}

void CGlobal::DrawNum(int sx, int sy, int Num)
{
	int BeamWidth = 0;

	//Num�� ���������� �� �ڸ��� ���� ����
	for( int i = 10 ; Num >= i ; i *= 10 ) {
		BeamWidth ++ ;
	}
	//ȭ�� ���� ���� �׷������� ��ȭ
	//x�� ���� �׷����� �׷����簢���� ���� ���� ��ǥ�Դϴ�
	int x = BeamWidth * NUM_WIDTH ;	
	for( int i = 0 ; i <= BeamWidth ; i ++ )
	{
		//������ ��ȭ(���� �� ����)
		//NumHandle�迭���� ��� ��ȣ 0���� �� 0���� �׷��� �ĺ� ��ȣ��
		//1���� �� 1���� �׷��� �ĺ� ��ȣ�� ��� �����Ƿ�,
		//DrawGraph(0 , 0 , NumHandle[0], TRUE)�̶�� �ϸ�
		//�� 0���� �׷����� ��ȭ �� �� �ִ� ���� ���� �ʴ�
		DrawGraph( x+sx , sy , NumHandle[ Num % 10 ], TRUE ) ;

		//��ȭ X��ǥ�� �̵�
		x -= NUM_WIDTH ;

		//���� ���� Ʋ�� ��ȭ�� ������ ������ �� �ڸ� ����
		Num /= 10 ;
	}
}