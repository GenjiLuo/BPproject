/////////////////////////////////////////////////////////////////////
typedef int INT;
typedef int BOOL;
typedef double REAL;
typedef char CHAR;

#define FALSE 0
#define TRUE 1
#define NOT !
#define AND &&
#define OR ||

#define MIN(x,y)	((x)>(y)?(y):(x))
#define MAX(x,y)	((x)>(y)?(x):(y))
#define sqr(x)		((x)*(x))

#define LO 0.1
#define HI 0.9
#define BIAS 0.5

#define NUM_LAYERS 3	//���������
#define N  2	//�������Ԫ����
#define M 2	//�������Ԫ����
#define ONECOLORBIT 256


typedef struct
{
	INT Units;		//��Ԫ����
	REAL* Output; //�����
	REAL* Activation; //����ֵ
	REAL* Error;  //�������
	REAL** Weight; //����Ȩ
	REAL** dWeight; //����ֵ
	REAL** WeightSave; //��������Ȩ
}LAYER; //�񾭲�ṹ

typedef struct
{
	LAYER**  Layer;	//�񾭲��ָ��
	LAYER*  OutputLayer; //ָ�������ָ��
	LAYER*  InputLayer; //ָ�������
	REAL Eta;     //��������
	REAL Alpha;   //ѧϰ��
	REAL Error;   //�����
	REAL Epsilon; //���ƾ���
 	//INT Numlayers;		//�������
}NET;   //������ṹ


////////////	����������    ////
//REAL Simioid(REAL input);		//����simioidֵ

void InitializeRandoms();		//�������������
INT RandomEqualINT(INT low,INT high);	//����һ�������������
REAL RandomEqualREAL(REAL Low,REAL High); //����һ��������С��С��
void RandomWeights(NET* Net);		//�����������Ȩ
void SaveWeights(NET* Net);			//��������Ȩ
void RestoreWeights(NET* Net);		//�ָ�����Ȩ
void SaveCharWeights(NET* Net);			//����ʶ���ַ�����Ȩ
void RestoreCharWeights(NET* Net);		//�ָ�ʶ���ַ�����Ȩ

void GenerateNetwork(NET* Net,int Unit[]);			//��������ռ�,�����ʾÿ������Ԫ��Ŀ
void SimulateNet(NET* Net,REAL* Input,REAL* Target,BOOL Training,BOOL Protocoling);	//������Ͷ������
void SetInput(NET* Net,REAL* Input,BOOL Protocoling);		//������������
void PropagateLayer(NET* Net,LAYER* Lower,LAYER* Upper);	//���㵱ǰ�������lowerΪ��һ�㣬upperΪ��ǰ��
void PropagateNet(NET* Net);	//���������������
void GetOutput(NET* Net,REAL* Output,BOOL Protocoling);	//������������
void ComputeOutputError(NET *Net,REAL* Target);		//�������������
void ComputeNetError(NET *Net);		//����������������������
void BackpropagateLayer(NET* Net,LAYER* Upper,LAYER* Lower);	//��һ�������ϲ㣬HIGHΪ�²㣨��ÿ���������������LOWERΪ�ϲ�
void BackpropagateNet(NET* Net);	//��������
void AdjustWeights(NET* Net);		//������������Ȩ���������
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAXIMAGEWIDTH	256
#define MAXIMAGEHEIGHT	256
extern HDC hWinDC;
void ReadImage(char *, char *, INT, INT);	//��ͼ��ϵ��
void GetPatternColor();	
void TrainingNet();		//ѵ������
void TrainCharNet();    //ѵ��ʶ���ַ����� 
BOOL RecognizateColor(int,int ,int,BOOL);	//�Ƿ���ɫ
void GetPixelBlueColor(HWND);		//		��õ�������ɫ
void GetPatternColor();		//�������ļ��еõ���ɫ����
void DetectPlateColor(unsigned char A[480][640]);		//�Գ�����ɫ���ж�λ,���Ѿ���λ�����ʾ��Ч�����浽BinaryImage��
BOOL ReadBmpFileHead(HFILE, char *);
void OpenImageFileDlg(char *OPDLTitle);
void Accurate(int* );		//�Գ��ƾ���λ����Ϣ����Rectangle��
void Derivative(int *,int *,int);		//������ĵ���	
void CharDevision(int *,int);			//�Գ��ƽ����ַ��ָ�
void CharImage(int num);
void WriteImage(LPSTR ImageFileName,  char *Image, int wImage, int hImage) ;
int smallest(float*,int);		//������������Сֵ�±�
LRESULT CALLBACK Renamechar(HWND, UINT, WPARAM, LPARAM);
void ReadRaw(LPSTR ImageFileName, char *oImage, int wImage, int hImage); //��ȡͼ����Ϣ��������Image[][]��
void Recochar();
void ShowLicense(int* lice);


BOOL LicenseBPMessageProc(HWND, UINT, WPARAM, LPARAM);
