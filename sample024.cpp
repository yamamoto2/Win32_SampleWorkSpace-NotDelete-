/*���ӁF�v�����g��\(�o�b�N�X���b�V��)�́A���p�́��}�[�N�ł�				*/
/*�L����͉E�̏ꏊ���Q�l���w�����L�T�[�o\�S��\41.G1_Win32API			*/
/*Ctrl + M �̌�ACtrl + L �ŁA�v���O�����S�̂̐܂肽����/�������ł��܂� */
/*Ctrl + M �̌�ACtrl + M �ŁA�u���b�N�̐܂肽����/�������ł��܂�		*/
/*���v���O���������͂ł�����A�֐����ׂ�A�v���O�����̉��������Ă݂悤	*/

/*
���w�b�_�[�t�@�C���ǂݍ��݂ɒǉ�

	#include <mmsystem.h>
	#include<digitalv.h>
	#pragma comment (lib, "winmm.lib")

���O���[�o���ϐ��ɒǉ�

	//�����Đ�����L�[�̏�Ԃ�����ϐ�
	int PlaySoundKey = MY_KEY_UP;

	//�L�[�{�[�h�̏�Ԃ�����ϐ�
	BYTE KeyBoard[256];

	//MP3�̃t�@�C�����Ǘ�����ϐ�
	MCI_OPEN_PARMS open1;
	MCI_OPEN_PARMS open2;
	MCI_OPEN_PARMS open3;

	//�Đ������Ǘ�����ϐ�
	MCI_PLAY_PARMS play1;
	MCI_PLAY_PARMS play2;
	MCI_PLAY_PARMS play3;

	//���y�t�@�C���̖߂�l������ϐ�
	int res_sound = 0;

���v���g�^�C�v�錾��ǉ�
	//����炷�֐�
	VOID MY_SOUND(VOID);

��MY_CHECK_KEYDOWN���C��
	�E�֐��̍ŏ��ɒǉ�
	//GetKeyboardState()�֐�
	//�����Ƃ��āABYTE�^�̔z��(256��)���󂯎��
	//���ׂẲ��z�L�[�̌��݂̏�Ԃ���x�Ɏ擾����
	//�ŏ�ʃr�b�g�� 1 �̂Ƃ��̓L�[��������Ă���
	//               0 �̂Ƃ��̓L�[��������Ă��Ȃ�

	//�ŉ��ʃr�b�g�� 1 �̂Ƃ��̓L�[���g�O����Ԃɂ���
	//               0 �̂Ƃ��̓g�O������������Ă���
	//���Ƃ��΁ACapsLock �L�[�� ON �ɂȂ��Ă���Ƃ��́A�g�O����ԂɂȂ�B

	//���ׂẲ��z�L�[�̌��݂̏�Ԃ���C�Ɏ擾����
	GetKeyboardState(KeyBoard);

	//���z�L�[�R�[�h�ŁAA�`Z�A0�`9�́AASCII�R�[�h���w��
	BYTE IskeyDown_W = KeyBoard['W'] & 0x80;
	BYTE IskeyDown_D = KeyBoard['D'] & 0x80;
	BYTE IskeyDown_A = KeyBoard['A'] & 0x80;
	BYTE IskeyDown_S = KeyBoard['S'] & 0x80;
	BYTE IsKeyDown_B = KeyBoard['B'] & 0x80;

	//W�L�[��������Ă��邩���肷��
	if (IskeyDown_W != 0)
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_UP;
	}

	//D�L�[��������Ă��邩���肷��
	if (IskeyDown_D != 0)
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_UP;
	}

	//S�L�[��������Ă��邩���肷��
	if (IskeyDown_S != 0)
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_UP;
	}

	//A�L�[��������Ă��邩���肷��
	if (IskeyDown_A != 0)
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_UP;
	}

	//B�L�[��������Ă��邩���肷��
	if (IsKeyDown_B != 0)
	{
		ShiftKey = MY_KEY_DOWN;
	}
	else
	{
		ShiftKey = MY_KEY_UP;
	}

	//P�L�[��������Ă��邩���肷��
	if (IsKeyDown_P != 0)
	{
		PlayKey = MY_KEY_DOWN;
	}
	else
	{
		PlayKey = MY_KEY_UP;
	}

	return;

	
������炷�֐���ǉ�
	
	//########## ����炷�֐� ##########
	VOID MY_SOUND(VOID)
	{
		//���g���̎Q�l�T�C�g
		//https://tomari.org/main/java/oto.html
		int Doremi[7] = {
			261,
			293,
			329,
			349,
			391,
			440,
			493
		};

		//�y��
		int Gakuhu[7][2]
		{
			{ Doremi[0],500 },
			{ Doremi[1],500 },
			{ Doremi[2],500 },
			{ Doremi[3],500 },
			{ Doremi[4],500 },
			{ Doremi[5],500 },
			{ Doremi[6],500 },
		};

		//�����������Đ����郂�[�h��؂�ւ�������
		int sound_mode = 5;

		if (PlaySoundKey == MY_KEY_DOWN)
		{
			switch (sound_mode)
			{
			case 0:
				//�r�[�v����炷
				//�֐��Ăяo���ƃT�E���h�Đ��͔񓯊��I�ɍs�Ȃ���

				MessageBeep(
					-1  // �T�E���h�^�C�v
				);
				Sleep(100);

				//�T�E���h�^�C�v�̎��
				//-1						�R���s���[�^�̃X�s�[�J���甭������W���I�ȃr�[�v��
				//MB_ICONASTERISK			SystemAsterisk		���b�Z�[�W�i���j
				//MB_ICONEXCLAMATION		SystemExclamation	���b�Z�[�W�i�x���j
				//MB_ICONHAND				SystemHand			�V�X�e���G���[
				//MB_ICONQUESTION			SystemQuestion		���b�Z�[�W�i�₢���킹�j
				//MB_OK						SystemDefault		��ʂ̌x����

			case 1:
				//���g���ŉ���炷
				//�֐��Ăяo���ƃT�E���h�Đ��͓����I�ɍs�Ȃ���

				Beep(
					440,	//���̎��g�����A37�`32767�̊Ԃ̒l�Ŏw��
					1000	//����炷���Ԃ��~���b�P�ʂŎw��
				);

			case 2:
				//�y���̂悤�ɉ��t����

				int i;
				for (i = 0; i < 7; i++)
				{
					Beep(Gakuhu[i][0], Gakuhu[i][1]);
				}

				break;

			case 3:
				//wave�t�@�C�����Đ�

				//�����Đ���������̂��|�C���g�I

				PlaySound(
					SOUND_KOUKA_1,	//�Đ��Ώۂ̃T�E���h
					NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
					SND_FILENAME	//�t�@�C�����Ŏw��
					| SND_LOOP		//�T�E���h�����[�v
					| SND_ASYNC		//�T�E���h��񓯊��Đ�
				);

				//�����~����
				//PlaySound(NULL,NULL,SND_PURGE);

				break;

			case 4:
				//wave�t�@�C�����Đ�

				//�����Đ��ł��Ȃ��̂��|�C���g�I

				PlaySound(
					SOUND_KOUKA_1,	//�Đ��Ώۂ̃T�E���h
					NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
					SND_FILENAME	//�t�@�C�����Ŏw��
					| SND_LOOP		//�T�E���h�����[�v
					| SND_ASYNC		//�T�E���h��񓯊��Đ�
				);

				PlaySound(
					SOUND_KOUKA_2,	//�Đ��Ώۂ̃T�E���h
					NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
					SND_FILENAME	//�t�@�C�����Ŏw��
					| SND_SYNC		//�T�E���h�𓯊��Đ�
				);

				break;

			case 5:
				//mp3�t�@�C�����Đ�
				mciSendCommand(
					open1.wDeviceID, 
					MCI_PLAY, 
					MCI_NOTIFY,				//MM_MCINOTIFY���Đ��I����,���s
					(DWORD_PTR)&play1
				);

				//mp3�t�@�C�����Đ�
				mciSendCommand(
					open2.wDeviceID,
					MCI_PLAY,
					MCI_DGV_PLAY_REPEAT,	//���[�v�Đ�
					(DWORD_PTR)&play2
				);

				//wave�t�@�C�����Đ�
				mciSendCommand(
					open3.wDeviceID,
					MCI_PLAY,
					MCI_NOTIFY,				//MM_MCINOTIFY���Đ��I����,���s
					(DWORD_PTR)&play3
				);
				break;

			}
		}
	}

��WM_CREATE�ɒǉ�
	�ESelectObject(bmp_dragon_mask.mhdc, bmp_dragon_mask.hbmp); �̉��ɒǉ�

	//MP3�̏���ݒ�
	open1.lpstrDeviceType = TEXT("MPEGVideo");
	open1.lpstrElementName = SOUND_BGM_MP3_1;

	//MP3���擾
	res_sound = mciSendCommand(
		0,
		MCI_OPEN, 			//�f�o�C�X���I�[�v��
		MCI_OPEN_TYPE		//MP3�t�@�C���̏ꍇ
		| MCI_OPEN_ELEMENT,	//MP3�t�@�C���̏ꍇ
		(DWORD_PTR)&open1);

	//MP3���ǂݍ��߂Ȃ������Ƃ�
	if (res_sound)
	{
		MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
	}

	//MP3�̏���ݒ�
	open2.lpstrDeviceType = TEXT("MPEGVideo");
	open2.lpstrElementName = SOUND_KOUKA_MP3_1;

	//mciSendCommand�ł́Awave�t�@�C�����ǂݍ��݉\

	//MP3���擾
	mciSendCommand(
		0,
		MCI_OPEN, 			//�f�o�C�X���I�[�v��
		MCI_OPEN_TYPE		//MP3�t�@�C���̏ꍇ
		| MCI_OPEN_ELEMENT,	//MP3�t�@�C���̏ꍇ
		(DWORD_PTR)&open2);

	//MP3���ǂݍ��߂Ȃ������Ƃ�
	if (res_sound)
	{
		MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
	}

	//wave�̏���ݒ�
	open3.lpstrDeviceType = (LPCWSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
	open3.lpstrElementName = SOUND_KOUKA_1;

	//wave���擾
	mciSendCommand(
		0,
		MCI_OPEN,			//�f�o�C�X���I�[�v��
		MCI_OPEN_TYPE		//wave�t�@�C���̏ꍇ
		| MCI_OPEN_TYPE_ID	//wave�t�@�C���̏ꍇ
		| MCI_OPEN_ELEMENT,	//wave�t�@�C���̏ꍇ
		(DWORD_PTR)&open3
		);

	//wave���ǂݍ��߂Ȃ������Ƃ�
	if (res_sound)
	{
		MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
	}

	//�R�[���o�b�N�E�B���h�E�̃n���h��
	//�E�C���h�E�v���V�[�W���̃E�B���h�E
	//��MM_MCINOTIFY���b�Z�[�W�������L�q
	play1.dwCallback = (DWORD)hwnd;
	play2.dwCallback = (DWORD)hwnd;
	play3.dwCallback = (DWORD)hwnd;

��WM_TIMER�ɒǉ�
	�EMY_MOVE_BITMAP(&bmp_dragon); �̉��ɒǉ�

	//����炷
	MY_SOUND();

�����b�Z�[�W��ǉ�

	case MM_MCINOTIFY:
	//MP3���Đ�

	if (lp == open1.wDeviceID)
	{
		//�Đ����I�������Ƃ�
		if (wp == MCI_NOTIFY_SUCCESSFUL)
		{
			//�V�[�N�o�[��擪�ɖ߂�
			mciSendCommand(
				open1.wDeviceID,
				MCI_SEEK,
				MCI_SEEK_TO_START,
				0
				);
		}
		return 0;
	}
	else if (lp == open2.wDeviceID)
	{
		//�Đ����I�������Ƃ�
		if (wp == MCI_NOTIFY_SUCCESSFUL)
		{
			//�V�[�N�o�[��擪�ɖ߂�
			mciSendCommand(
			open2.wDeviceID,
			MCI_SEEK,
			MCI_SEEK_TO_START,
			0
			);
		}
		return 0;
	}
	else if (lp == open3.wDeviceID)
	{
		//�Đ����I�������Ƃ�
		if (wp == MCI_NOTIFY_SUCCESSFUL)
		{
			//�V�[�N�o�[��擪�ɖ߂�
			mciSendCommand(
			open3.wDeviceID,
			MCI_SEEK,
			MCI_SEEK_TO_START,
			0
			);
		}
		return 0;
	}

	break;

��WM_DESTROY�ɒǉ� ����������

	�EDeleteDC(hdc_double); �̉��ɒǉ�

	//MP3�t�@�C�������
	mciSendCommand(open1.wDeviceID, MCI_CLOSE, 0, 0);
	mciSendCommand(open2.wDeviceID, MCI_CLOSE, 0, 0);

	//wave�t�@�C�������
	mciSendCommand(open3.wDeviceID, MCI_CLOSE, 0, 0);

*/


























































//########## �w�b�_�[�t�@�C���ǂݍ��� ##########

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <wingdi.h>
#pragma comment (lib, "msimg32.lib")

//���������� �w�b�_�[�t�@�C���ǂݍ��݂ɒǉ� ����������

#include <mmsystem.h>
#include<digitalv.h>
#pragma comment (lib, "winmm.lib")

//���������� �w�b�_�[�t�@�C���ǂݍ��݂ɒǉ� ����������

//########## �}�N����` ##########

//�����ō쐬���鳨��޳�׽�̖��O
#define MY_WIN_CLASS "MY_WIN_CLASS"

//�E�B���h�E�̏ꏊ��傫����ݒ�
#define WIN_X		100		//���̈ʒu
#define WIN_Y		100		//�c�̈ʒu
#define WIN_WIDTH	500		//��
#define WIN_HEIGHT	500		//����

//�G���[���b�Z�[�W
#define ERR_MSG_TITLE			TEXT("ERROR")

//\�̓G�f�B�^��̉��s���s�������Ƃ��ɋL�q����
#define ERR_MSG_NO_WIN_CLASS	TEXT("�E�B���h�E�N���X��\
�o�^�ł��܂���ł���\n�v���O�������I�����܂�")

#define ERR_MSG_NO_WIN_CREATE	TEXT("�E�B���h�E\
���쐬�ł��܂���ł���\n�v���O�������I�����܂�")

#define ERR_MSG_NO_READ_FONT	TEXT("�t�H���g��\
�ǂݍ��߂܂���ł���\n�v���O�������I�����܂�")

//�E�B���h�E�̃T�C�Y��ύX�ł��Ȃ�����
#define WS_STATIC_WINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//�E�B���h�E�̃^�C�g�����Ȃ���
#define WS_NOT_TITLE WS_POPUP | WS_BORDER

//���ł�PC�ɃC���X�g�[������Ă���t�H���g
#define FNT_MS_GOTHIC TEXT("�l�r �S�V�b�N")
#define FNT_MS_MINCHO TEXT("�l�r ����")

//�ꎞ�I�ɓǂݍ��ރt�H���g
#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//�t�H���g�̏ꏊ
#define FNT_JUD_NAME	TEXT("Judge Hard")

#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//�t�H���g�̏ꏊ
#define FNT_TANU_NAME	TEXT("���ʂ������}�W�b�N")

//�~����
#define MY_PI 3.1415926

//���_�̍ő吔
#define CHOTEN_MAX	30

//�r�b�g�}�b�v�ǂݍ��݃G���[
#define ERR_MSG_NO_READ_BMP	TEXT("�r�b�g�}�b�v��\
	 �ǂݍ��߂܂���ł���\n�v���O�������I�����܂�")

//�h���S���̃r�b�g�}�b�v�̏ꏊ
//#define BMP_DRA_PASS		TEXT(".\\MY_BITMAP\\mon23\\mon_255.bmp")

//�h���S���̃r�b�g�}�b�v�̏ꏊ�i�A���t�@�`���l���t���j
#define BMP_DRA_PASS		TEXT(".\\MY_BITMAP\\mon23\\mon_255_alpha.bmp")

//�h���S���̓��ߏ���
#define BMP_DRA_WH_PASS	TEXT(".\\MY_BITMAP\\mon23\\mon_255_white.bmp")	//�h���S���̃r�b�g�}�b�v(�w�i��)�̏ꏊ
#define BMP_DRA_MS_PASS	TEXT(".\\MY_BITMAP\\mon23\\mon_255_bw.bmp")		//�h���S���̃}�X�N�̏ꏊ

////�R�����g�A�E�g
//#define TIMER_ID_1	1		//�^�C�}�[�P
//#define TIMER_ID_2	2		//�^�C�}�[�Q

//���������� �}�N����`�ɒǉ� ����������

//MP3�ǂݍ��݃G���[
#define ERR_MSG_NO_READ_MP3	TEXT("MP3��\
	 �ǂݍ��߂܂���ł���\n�v���O�������I�����܂�")

//���ʉ�
#define SOUND_KOUKA_1		TEXT(".\\MY_SOUND\\don.wav")
#define SOUND_KOUKA_2		TEXT(".\\MY_SOUND\\chime.wav")

#define SOUND_KOUKA_MP3_1	TEXT(".\\MY_SOUND\\magical_1.mp3")
#define SOUND_KOUKA_MP3_2	TEXT(".\\MY_SOUND\\magical_2.mp3")

//BGM
#define SOUND_BGM_MP3_1		TEXT(".\\MY_SOUND\\field.mp3")

//���������� �}�N����`�ɒǉ� ����������

#define TIMER_ID_FPS	100	//FPS�^�C�}�[

#define DISP_FPS		60	//��ʂ�FPS
#define AVE_FPS			60	//���ς����T���v����

#define MY_KEY_DOWN	1	//�L�[���������Ƃ�
#define MY_KEY_UP	0	//�L�[���グ���Ƃ�

#define MY_KEY_ARROW_UP		0	//����L�[
#define MY_KEY_ARROW_RIGHT	1	//�E���L�[
#define MY_KEY_ARROW_DOWN	2	//�����L�[
#define MY_KEY_ARROW_LEFT	3	//�����L�[

#define MY_KEY_SHIFT		0	//�V�t�g�L�[

#define MY_SPEED_NORMAL		1	//���ʂ̃X�s�[�h
#define MY_SPEED_METEOR		8	//�����X�s�[�h(METEOR:���e�I:覐�)

//########## �񋓌^ ##########

//�E�B���h�E�̃T�C�Y�ύX���[�h
enum WIN_MODE {
	WIN_RESZ_OK,	//0�F�E�B���h�E�T�C�Y�̕ύX���ł���
	WIN_RESZ_NG,	//1�F�E�B���h�E�T�C�Y�̕ύX���ł��Ȃ�
	WIN_NO_TITLE	//2�F�E�B���h�E�̃^�C�g�����Ȃ���
};

//########## �\���� ##########
struct MY_STRUCT_BITMAP {
	LPCTSTR filepass;	//�r�b�g�}�b�v�̃t�@�C���p�X�Ɩ��O
	HBITMAP hbmp;		//�r�b�g�}�b�v�̃n���h��
	HDC mhdc;			//�������f�o�C�X�R���e�L�X�g���쐬
	BITMAP bmp;			//�r�b�g�}�b�v�\����
	int x;				//�r�b�g�}�b�v�̕\���ʒu(X���W)
	int y;				//�r�b�g�}�b�v�̕\���ʒu(Y���W)
	int width;			//�r�b�g�}�b�v�̕����擾
	int height;			//�r�b�g�}�b�v�̍������擾
};

//########## ���O�̍Ē�` ##########

typedef MY_STRUCT_BITMAP	MY_BMP;

//########## �v���g�^�C�v�錾 ##########

//�E�B���h�E�v���V�[�W��
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//�����̃E�B���h�E�N���X���쐬����
WNDCLASS MY_CreateWindowClass(HINSTANCE);

//�E�B���h�E�𐶐�����
HWND MY_CreateWindow(HINSTANCE, int);

//�N���C�A���g�̈��ݒ肷��
VOID MY_SetClientSize(HWND);

//�t�H���g��ݒ肷��
HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

//�t�H���g��ݒ肵�ĕ`�悷��
VOID MY_SetFontDraw(HDC);

//����`�悷��
VOID MY_DRAW_LINE(HDC);

//�}�`��`�悷��
VOID MY_DRAW_GRAPH(HDC);

//�y�����g�p���ĕ`�悷��֐�
VOID MY_DRAW_PEN(HDC);

//�u���V���g�p���ĕ`�悷��֐�
VOID MY_DRAW_BRUSH(HDC);

//���p�`��h��Ԃ��ĕ`�悷��
VOID MY_DRAW_POLYGON(HDC);

//�����̑��p�`��h��Ԃ��ĕ`��
VOID MY_DRAW_POLYPOLYGON(HDC);

//�Z�p�`��h��Ԃ��ĕ`�悷��
VOID MY_DRAW_PENTAGON(HDC);

//�p�b�N�}����h��Ԃ��ŕ`�悷��
VOID MY_DRAW_PACMAN(HDC);

//�����X�^�[�{�[����h��Ԃ��ŕ`�悷��
VOID MY_DRAW_MONBALL(HDC);

//�_�u���o�b�t�@�����O�̐ݒ������
VOID MY_SetDoubleBufferring(HWND);

//�r�b�g�}�b�v��`�悷��֐�
VOID MY_DRAW_BITMAP(HDC);

//��ʍX�V�̎������擾����֐�
BOOL MY_FPS_UPDATE(VOID);

//�w�肵��FPS�ɂȂ�悤�ɑ҂֐�
VOID MY_FPS_WAIT(VOID);

//���z�L�[�R�[�h�𐮌`����֐�
VOID MY_FORMAT_KEYCODE(WPARAM, int);

//���z�L�[�R�[�h�𕶎��ɐ��`����֐�
VOID MY_FORMAT_KEYCHAR(WPARAM, int);

//�ǂ̃L�[�������Ă��邩����
VOID MY_CHECK_KEYDOWN(VOID);

//�r�b�g�}�b�v���ړ�������֐�
VOID MY_MOVE_BITMAP(MY_BMP *);

//���������� �v���g�^�C�v�錾��ǉ� ����������

//����炷�֐�
VOID MY_SOUND(VOID);

//���������� �v���g�^�C�v�錾��ǉ� ����������

//########## �O���[�o���ϐ��̐錾�Ə����� ##########

//�}�E�X�̍��W���Ǘ�����\����
POINT pt_Mouse = { 0,0 };

//�E�B���h�E�T�C�Y���Ǘ�����\����
RECT window_Size = { 0, 0, 0, 0 };

//�̈���Ǘ�����\����
RECT rect_w;	//�E�B���h�E�̈���Ǘ�
RECT rect_c;	//�N���C�A���g�̈���Ǘ�

				//�E�B���h�E�̃��[�h��ݒ�
int win_mode = (int)WIN_RESZ_OK;

//�_�u���o�b�t�@�����O�p
HBITMAP hbmp_double;
HDC     hdc_double;

//�����ō쐬�����r�b�g�}�b�v�\����
MY_BMP bmp_dragon;
MY_BMP bmp_dragon_white;
MY_BMP bmp_dragon_mask;

//�R�����g�A�E�g
////unsigen�F�����Ȃ�
////���C�����[�v�ŃJ�E���g������ϐ�
//unsigned int mainLoop_cnt = 0;
//
////�^�C�}�[�P�ŃJ�E���g����ϐ�
//unsigned int timer_1_cnt = 0;
//
////�^�C�}�[�Q�ŃJ�E���g����ϐ�
//unsigned int timer_2_cnt = 0;

//FPS�̃^�C�}�[�ŃJ�E���g����ϐ�
unsigned int timer_fps_cnt = 0;

float		fps;		//FPS
DWORD		fps_sta_tm;	//0�t���[���ڂ̊J�n����
DWORD		fps_end_tm;	//�ݒ肵���t���[���̏I������
DWORD		fps_count;	//�t���[���̃J�E���g

						//�L�[�R�[�h������ϐ�
TCHAR Str_KeyCode[64] = TEXT("�L�[�R�[�h�F--");

//�L�[����������ϐ�
TCHAR Str_KeyValue[64] = TEXT("�L�[�����F--");

//�L�[�{�[�h�̏�Ԃ�����ϐ�
TCHAR Str_KeyState[64] = TEXT("�L�[�̏��:--");

//���L�[�̏�Ԃ�����z��
int ArrowKey[4] = {
	MY_KEY_UP,
	MY_KEY_UP,
	MY_KEY_UP,
	MY_KEY_UP };

//�V�t�g�L�[�̏�Ԃ�����ϐ�
int ShiftKey = MY_KEY_UP;

//�ړ����x��ۑ�����ϐ�
int Speed = MY_SPEED_NORMAL;

//���������� �O���[�o���ϐ��ɒǉ� ����������

//�����Đ�����L�[�̏�Ԃ�����ϐ�
int PlaySoundKey = MY_KEY_UP;

//�L�[�{�[�h�̏�Ԃ�����ϐ�
BYTE KeyBoard[256];

//MP3�̃t�@�C�����Ǘ�����ϐ�
MCI_OPEN_PARMS open1;
MCI_OPEN_PARMS open2;
MCI_OPEN_PARMS open3;

//�Đ������Ǘ�����ϐ�
MCI_PLAY_PARMS play1;
MCI_PLAY_PARMS play2;
MCI_PLAY_PARMS play3;

//���y�t�@�C���̖߂�l������ϐ�
int res_sound = 0;

//���������� �O���[�o���ϐ��ɒǉ� ����������

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{

	//�X�̃E�B���h�E�����ʂ���l(�E�B���h�E�n���h��)
	HWND hwnd;

	//�E�B���h�E�N���X���Ǘ�����\����
	WNDCLASS winc;

	//���b�Z�[�W��ۑ�����\����
	MSG msg;

	//�����̃E�B���h�E�N���X���쐬����֐�
	winc = MY_CreateWindowClass(hInstance);

	//�E�B���h�E�N���X��o�^����
	if (!RegisterClass(&winc))
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(NULL, ERR_MSG_NO_WIN_CLASS, ERR_MSG_TITLE, MB_OK);

		//�o�^���ł��Ȃ�������A�v���O�������I������
		return 0;
	}

	//�E�B���h�E�𐶐�����(�T�C�Y�ύX�Ȃ�)
	hwnd = MY_CreateWindow(hInstance, win_mode);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd == NULL)
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(NULL, ERR_MSG_NO_WIN_CREATE, ERR_MSG_TITLE, MB_OK);

		//�������I��������
		return 0;
	}

	//�N���C�A���g�̈���Đݒ肷��
	MY_SetClientSize(hwnd);

	//�_�u���o�b�t�@�����O�̐ݒ������
	MY_SetDoubleBufferring(hwnd);

	//�E�B���h�E��\��
	ShowWindow(hwnd, SW_SHOW);

	//���b�Z�[�W���󂯎�葱����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//���z�L�[�R�[�h�𕶎��ɕϊ�����
		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}
	////�R�����g�A�E�g
	//while (TRUE)
	//{
	//	//�f�b�h�^�C�����g��
	//	//�f�b�h�^�C���F�E�B���h�E�����b�Z�[�W���������Ă��Ȃ����Ԃ̂���
	//	//�u�A�C�h����ԁv�u�V�x���ԁv�Ȃǂ̕\�����@������
	//	//�����[�U����L�[�{�[�h��}�E�X�Ȃǂ̓��͑҂��ȂǂŁA
	//	//  CPU�����������Ă��Ȃ����

	//	//�f�b�h�^�C�������ׂ�(0�ȊO��ү���ގ擾 / 0���ޯ�����)
	//	BOOL PeekRet = PeekMessage(
	//		&msg,		//MSG�\���̂̃|�C���^
	//		NULL,		//ү���ގ擾����޳�̃n���h��/�S���Ȃ�NULL
	//		0,			//���b�Z�[�W�̍ŏ��l / �Ȃ��ꍇ��0
	//		0,			//���b�Z�[�W�̍ő�l / �Ȃ��ꍇ��0
	//		PM_REMOVE	//���b�Z�[�W�L���[���烁�b�Z�[�W���폜
	//	);

	//	//�f�b�h�^�C���̂Ƃ�
	//	if (PeekRet == TRUE)
	//	{
	//		//���b�Z�[�W��WM_QUIT�Ȃ烋�[�v�𔲂���
	//		if (msg.message == WM_QUIT)
	//		{
	//			break;
	//		}

	//		//���̃��b�Z�[�W�̏���������
	//		DispatchMessage(&msg);
	//	}

	//	//�f�b�h�^�C���̂Ƃ�
	//	if (PeekRet == FALSE)
	//	{
	//		//unsigned int�̍ő�l��菬�����ꍇ
	//		if (mainLoop_cnt < UINT_MAX)
	//		{
	//			mainLoop_cnt++;

	//			//�������[�W�����𔭐�
	//			InvalidateRect(hwnd, NULL, FALSE);

	//			//��ʂ��A�����ɍĕ`�悷��
	//			UpdateWindow(hwnd);
	//		}
	//	}
	//}

	return msg.wParam;
}

//########## ��ʍX�V�̎������擾����֐� ##########
BOOL MY_FPS_UPDATE(VOID)
{
	//1�t���[���ڂȂ玞�����L��
	if (fps_count == 0)
	{
		//GetTickCount�F
		//Windows���N�����Ă��猻�݂܂ł̎�����
		//�~���b�Ŏ擾
		fps_sta_tm = GetTickCount();
	}

	//60�t���[���ڂȂ畽�ς��v�Z����
	if (fps_count == AVE_FPS)
	{
		//���݂̎������~���b�Ŏ擾
		fps_end_tm = GetTickCount();

		//.0f��float�^�Ōv�Z
		//���ϓI��FPS�l���v�Z
		fps = 1000.0f / ((fps_end_tm - fps_sta_tm) / (float)AVE_FPS);

		fps_sta_tm = fps_end_tm;
		fps_count = 0;

	}

	fps_count++;

	return true;
}

//########## �w�肵��FPS�ɂȂ�悤�ɑ҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	//���݂̎������~���b�Ŏ擾
	DWORD now_tm = GetTickCount();

	//1�t���[���ڂ�����ۂɂ����������Ԃ��v�Z
	DWORD keika_tm = now_tm - fps_sta_tm;

	//�҂ׂ����� = ������ׂ����� - ���ۂɂ�����������;
	DWORD wait_tm = (fps_count * 1000 / DISP_FPS) - (keika_tm);

	//�҂ׂ����Ԃ��������ꍇ
	if (wait_tm > 0 && wait_tm < 2000)
	{
		//�~���b���A�����𒆒f����
		Sleep(wait_tm);
	}
}

//########## �_�u���o�b�t�@�����O�̐ݒ������֐� ##########
VOID MY_SetDoubleBufferring(HWND hWnd)
{

	//�_�u���o�b�t�@�����O�Ƃ́H
	//���݂̕`����@�́A��U�A��ʂ����������邽�߁A��ʂ�������Ă���
	//�`�揈���𒼐ڕ\������̂ł͂Ȃ��A�������̒��ɕ`�悵
	//�Ō�Ƀ������̒��ɂ�����̂�\�����邱�ƂŁA��������Ȃ���
	//������A�u�_�u���o�b�t�@�����O�v�Ƃ���

	// �E�C���h�E�̃f�o�C�X�R���e�L�X�g�̃n���h�����擾
	HDC hdc = GetDC(hWnd);

	//�������̒��ɉ摜���쐬
	hbmp_double = CreateCompatibleBitmap(hdc, rect_c.right, rect_c.bottom);

	//�������̒��Ƀf�o�C�X�R���e�L�X�g�̃n���h�����쐬
	hdc_double = CreateCompatibleDC(hdc);

	//�f�o�C�X�R���e�L�X�g�ɉ摜��ݒ�
	SelectObject(hdc_double, hbmp_double);

}

//########## �����̃E�B���h�E�N���X���쐬����֐� ##########
WNDCLASS MY_CreateWindowClass(HINSTANCE hInstance)
{
	//�E�B���h�E�N���X���쐬
	WNDCLASS winc;

	//�u���V���쐬
	HBRUSH brush;

	//�u���V�̐F��ݒ�
	brush = CreateSolidBrush(RGB(255, 255, 255));

	//�E�B���h�E�N���X�̐ݒ�͂�������
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = MY_WndProc;
	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = brush;
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT(MY_WIN_CLASS);

	//�E�B���h�E�N���X��Ԃ�
	return winc;
}

//########## �E�B���h�E�𐶐�����֐� ##########
HWND MY_CreateWindow(HINSTANCE hInstance, int mode)
{
	//�X�̃E�B���h�E�����ʂ���l(�E�B���h�E�n���h��)
	HWND hwnd;

	switch (mode)
	{
	case WIN_RESZ_OK:
		//�E�B���h�E�̃T�C�Y�ύX���ł���

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("�����œo�^�����E�B���h�E�N���X"),
			WS_OVERLAPPEDWINDOW,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;

	case WIN_RESZ_NG:
		//�E�B���h�E�̃T�C�Y�ύX���ł��Ȃ�

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("�����œo�^�����E�B���h�E�N���X"),
			WS_STATIC_WINDOW,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;

	case WIN_NO_TITLE:
		//�E�B���h�E�̃^�C�g����\�����Ȃ�

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("�����œo�^�����E�B���h�E�N���X"),
			WS_NOT_TITLE,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;
	}

	//�E�B���h�E�n���h����Ԃ�
	return hwnd;
}

//########## �N���C�A���g�̈�̐ݒ������֐� ##########
VOID MY_SetClientSize(HWND hWnd)
{
	//�̈���Ǘ�����\����
	RECT rect_set;

	//�ŏ��̃N���C�A���g�̗̈��ݒ�
	rect_set.top = WIN_Y;
	rect_set.left = WIN_X;
	rect_set.bottom = WIN_HEIGHT;
	rect_set.right = WIN_WIDTH;

	//�E�B���h�E�̈���擾
	GetWindowRect(hWnd, &rect_w);

	//�N���C�A���g�̈���擾
	GetClientRect(hWnd, &rect_c);

	//�N���C�A���g�̈�̕����C��
	//�@�@�@�@�@�@�@�@((�E�C���h�E�̉��T�C�Y)       - (�N���C�A���g�̉��T�C�Y));
	//�E�C���h�E�̉��T�C�Y - �N���C�A���g�̉��T�C�Y �� �E�C���h�E�g�̉��������܂�
	//���߂��E�C���h�E�g�̕����A���X�̕��ɉ��Z����
	rect_set.right += ((rect_w.right - rect_w.left) - (rect_c.right - rect_c.left));

	//�N���C�A���g�̈�̍������C��
	//                 ((�E�C���h�E�̏c�T�C�Y)       - (�N���C�A���g�̏c�T�C�Y));
	//�E�C���h�E�̏c�T�C�Y - �N���C�A���g�̏c�T�C�Y �� �E�C���h�E�g�̏c�������܂�
	//���߂��E�C���h�E�g�̍������A���X�̍����ɉ��Z����
	rect_set.bottom += ((rect_w.bottom - rect_w.top) - (rect_c.bottom - rect_c.top));

	//�N���C�A���g�̈�̏ꏊ�ƃT�C�Y���Đݒ�
	SetWindowPos(
		hWnd,					//�E�B���h�E�n���h��
		HWND_TOP,				//�E�B���h�E��O�̖ʂɂ���
		rect_set.left,			//�E�B���h�E��X���W
		rect_set.top,			//�E�B���h�E��Y���W
		rect_set.right,			//�E�B���h�E�̕�
		rect_set.bottom,		//�E�B���h�E�̍���
		SWP_SHOWWINDOW);		//�E�B���h�E��\��

	//�T�C�Y�𓯂��ɂ���
	rect_c.bottom = WIN_HEIGHT;
	rect_c.right = WIN_WIDTH;
}

//########## �摜��`�悷��֐� ##########
VOID MY_DRAW(HDC hdc)
{
	//�}�E�X�̍��W�̕����������ϐ�
	TCHAR Str_X_Y[64];

	//��ʂ̑傫���̕����������ϐ�
	TCHAR Str_CX_CY[64];

	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm;

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm);

	//�����̕`�敔���ɂ��̂܂܏㏑������
	//SetBkMode(hdc, TRANSPARENT);			//�w�i��h��Ԃ��Ȃ�

	//������`�敔���̔w�i����������
	SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�

	SetTextColor(hdc, RGB(0, 0, 0));		//�����F�𔒂ɂ���
	SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�����ɂ���

											//�}�E�X�̍��W�𐮌`
	wsprintf(Str_X_Y, TEXT("�}�E�X�̈ʒu(X:%03d,Y:%03d)"), pt_Mouse.x, pt_Mouse.y);

	//�}�E�X�̍��W��`��
	TextOut(hdc, 100, tm.tmHeight * 0, Str_X_Y, lstrlen(Str_X_Y));

	//��ʂ̑傫���𐮌`
	wsprintf(Str_CX_CY, TEXT("��ʂ̑傫��(X:%03d,Y:%03d)"), window_Size.right, window_Size.bottom);

	//��ʂ̑傫����`��
	TextOut(hdc, 100, tm.tmHeight * 1, Str_CX_CY, lstrlen(Str_CX_CY));

	////+++++ ���C�����[�v�ŃJ�E���g ++++++++++++++++++++
	//TCHAR Str_mainLoop_Cnt[64];
	//wsprintf(Str_mainLoop_Cnt, TEXT("���C�����[�v�̃J�E���g�F%06d"), mainLoop_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 2, Str_mainLoop_Cnt, lstrlen(Str_mainLoop_Cnt));

	////+++++ �^�C�}�[�P�ŃJ�E���g ++++++++++++++++++++
	//TCHAR Str_Timer_1_Cnt[64];
	//wsprintf(Str_Timer_1_Cnt, TEXT("�^�C�}�[�P�̃J�E���g�F%06d"), timer_1_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 3, Str_Timer_1_Cnt, lstrlen(Str_Timer_1_Cnt));

	////+++++ �^�C�}�[�Q�ŃJ�E���g ++++++++++++++++++++
	//TCHAR Str_Timer_2_Cnt[64];
	//wsprintf(Str_Timer_2_Cnt, TEXT("�^�C�}�[�Q�̃J�E���g�F%06d"), timer_2_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 4, Str_Timer_2_Cnt, lstrlen(Str_Timer_2_Cnt));

	//+++++ FPS��\�� ++++++++++++++++++++

	//FPS�l�𐮌`���邽�߂̕ϐ�
	CHAR Str_fps_C[64];
	size_t wLen = 0;
	errno_t err = 0;

	//FPS�l�𐮌`
	sprintf(Str_fps_C, "FPS�F%03.1lf", fps);

	//FPS�l��\�����邽�߂̕ϐ�
	TCHAR Str_fps_W[64];

	//���P�[���w��
	setlocale(LC_ALL, "japanese");

	//��������}���`�o�C�g�������烏�C�h�����ɕϊ�
	err = mbstowcs_s(
		&wLen,				//�ϊ����ꂽ������
		Str_fps_W,			//�ϊ����ꂽ���C�h����
		strlen(Str_fps_C),	//�ϊ����镶����
		Str_fps_C,			//�ϊ�����}���`�o�C�g����
		_TRUNCATE			//�o�b�t�@�Ɏ��܂邾���̕�����܂ŕϊ�
	);

	TextOut(hdc, 100, tm.tmHeight * 2, Str_fps_W, lstrlen(Str_fps_W));

	//���z�L�[�R�[�h��`��
	TextOut(hdc, 100, tm.tmHeight * 3, Str_KeyCode, lstrlen(Str_KeyCode));

	//���z�L�[��Ԃ𕶎��ɂ��ĕ`��
	TextOut(hdc, 100, tm.tmHeight * 4, Str_KeyState, lstrlen(Str_KeyState));

	//���z�L�[�R�[�h�𕶎��ɂ��ĕ`��
	TextOut(hdc, 100, tm.tmHeight * 5, Str_KeyValue, lstrlen(Str_KeyValue));

}

//########## �t�H���g��ݒ肵�ĕ�����`�悷�� ##########
VOID MY_SetFontDraw(HDC hdc)
{
	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm_d;

	//�\�����镶����
	TCHAR STR1[] = TEXT("����ɂ��́B");
	TCHAR STR2[] = TEXT("Hello,123*");
	TCHAR STR3[] = TEXT("�X���̃I�X�X���I");

	//�`�悷�镶���̈ʒu(X���W)
	int Str_X = 0;

	//�`�悷�镶���̈ʒu(Y���W)
	int Str_Y = 50;

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//------------------------------------------------
	//PC�ɃC���X�g�[���ς̃t�H���g���g�p����
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Ins;

	//�t�H���g���쐬
	hfnt_Ins = MY_CreateFont(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		FNT_MS_MINCHO,		//�t�H���g�̖��O
		32,				//�t�H���g�̃T�C�Y
		0,					//�`�悷��Ƃ��̊p�x
		SHIFTJIS_CHARSET	//�����R�[�h
	);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Ins);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR1, lstrlen(STR1));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Ins);

	//------------------------------------------------
	//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(ANSI:�p���̂�)
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Not_ANSI;

	//�t�H���g���쐬
	hfnt_Not_ANSI = MY_CreateFont(hdc, FNT_JUD_NAME, 100, 0, ANSI_CHARSET);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Not_ANSI);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR2, lstrlen(STR2));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Not_ANSI);

	//------------------------------------------------
	//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(Shift-JIS:���{��)
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Not_SJIS;

	//�t�H���g���쐬
	hfnt_Not_SJIS = MY_CreateFont(hdc, FNT_TANU_NAME, 32, 0, SHIFTJIS_CHARSET);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Not_SJIS);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR3, lstrlen(STR3));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Not_SJIS);

	return;
}

//########## �t�H���g��ݒ肷��֐� ##########
HFONT MY_CreateFont(HDC hdc, LPCTSTR fontName, int size, int angle, int charset)
{

	HFONT hFont;
	hFont = CreateFont(
		size,					//�t�H���g�̍��� / 0�Ȃ�f�t�H���g(�傫��)
		0,						//������		 / 0�Ȃ玩���v�Z

		angle,					//�e�L�X�g�̊p�x
								//�������甽���v���� 1/10 �x�P�ʂŊp�x���w��
								//   0(  0�x) �Ȃ�� ������E�֕`��
								// 900( 90�x) �Ȃ�� �������֕`��
								//1800(180�x) �Ȃ�� �E���獶�֕`��
								//2700(270�x) �Ȃ�� �ォ�牺�֕`��

		0,						//�x�[�X���C���Ƃ����Ƃ̊p�x
		FW_REGULAR,				//�t�H���g�̏d���i�����j
		FALSE,					//�C�^���b�N��
		FALSE,					//�A���_�[���C��
		FALSE,					//�ł�������

		charset,				//�����Z�b�g
								//ANSI      ���g���Ȃ�� ANSI_CHARSET
								//Shift-JIS ���g���Ȃ�� SHIFTJIS_CHARSET
								//�f�t�H���g���g���Ȃ�� DEFAULT_CHARSET

		OUT_DEFAULT_PRECIS,	//�o�͐��x
		CLIP_DEFAULT_PRECIS,	//�N���b�s���O���x
		PROOF_QUALITY,			//�o�͕i��
		FIXED_PITCH | FF_MODERN,//�s�b�`�ƃt�@�~���[
		fontName);				//�t�H���g�̏��̖�

	return hFont;
}

//########## ����`�悷��֐� ##########
VOID MY_DRAW_LINE(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//����`��
	//++++++++++++++++++++++++++++++++++++++++

	//XY���W���P�i�[�ł���POINT�\����
	POINT pt_line = { 250,250 };

	//�����ǂ�����`���n�߂邩�ݒ肷��
	//�J�����g�|�W�V�����Ƃ���
	MoveToEx(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x,			//�`���n�߂�X���W
		pt_line.y,			//�`���n�߂�Y���W
		NULL);				//�ȑO�̃J�����g�|�W�V�����擾/�K�v�Ȃ��Ȃ�NULL

							//����`��(�c�_)
	LineTo(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x,			//�`���I���X���W
		pt_line.y + 200);	//�`���I���Y���W

							//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x,			//�`���n�߂�X���W
		pt_line.y,			//�`���n�߂�Y���W
		NULL);				//�ȑO�̃J�����g�|�W�V����/�K�v�Ȃ��Ȃ�NULL

							//����`��(���_)
	LineTo(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x + 200,	//�`���I���X���W
		pt_line.y);		//�`���I���Y���W

						//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x,			//�`���n�߂�X���W
		pt_line.y,			//�`���n�߂�Y���W
		NULL);				//�ȑO�̃J�����g�|�W�V����/�K�v�Ȃ��Ȃ�NULL

							//����`��(�΂ߖ_)
	LineTo(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_line.x + 200,	//�`���I���X���W
		pt_line.y + 200);	//�`���I���Y���W

							//++++++++++++++++++++++++++++++++++++++++
							//�A���������̕`���`��
							//++++++++++++++++++++++++++++++++++++++++

							//�A���������̍��W
	POINT pt_ren[5];
	int POINT_CNT = 5;	//���W�̐�

						//�l�p�̍���
	pt_ren[0].x = 50;
	pt_ren[0].y = 300;

	//�l�p�̉E��
	pt_ren[1].x = 200;
	pt_ren[1].y = 300;

	//�l�p�̉E��
	pt_ren[2].x = 200;
	pt_ren[2].y = 400;

	//�l�p�̍���
	pt_ren[3].x = 50;
	pt_ren[3].y = 400;

	//�l�p�̍���
	pt_ren[4].x = 50;
	pt_ren[4].y = 300;

	int sw_ren = 1;

	if (sw_ren == 0)
	{
		//�����ǂ�����`���n�߂邩�ݒ肷��
		MoveToEx(hdc, pt_ren[0].x, pt_ren[0].y, NULL);

		//�A����������`�悷��
		PolylineTo(
			hdc,			//�f�o�C�X�R���e�L�X�g�̃n���h��
			pt_ren,			//POINT�\���̔z��̃|�C���^
			POINT_CNT);		//�`�悷����W�̐�
	}
	else
	{
		//�J�����g�|�W�V�������g�p�����A�A�����������ꊇ�ŕ`��
		Polyline(
			hdc,			//�f�o�C�X�R���e�L�X�g�̃n���h��
			pt_ren,			//POINT�\���̔z��̃|�C���^
			POINT_CNT);		//�`�悷����W�̐�
	}

	//++++++++++++++++++++++++++++++++++++++++
	//�A���������𕡐��ɕ����ĕ`��
	//++++++++++++++++++++++++++++++++++++++++

	int LINE_HUKU_CNT = 2;	//���̐�

							//�A���������̍��W
	DWORD split[2] = {
		3,	//�R�ł܂Ƃ߂�
		4 };	//�S�ł܂Ƃ߂�

	POINT pt_huku[7];

	//--------------------
	pt_huku[0].x = 50;
	pt_huku[0].y = 250;

	pt_huku[1].x = 75;
	pt_huku[1].y = 350;

	pt_huku[2].x = 100;
	pt_huku[2].y = 250;
	//--------------------
	pt_huku[3].x = 125;
	pt_huku[3].y = 350;

	pt_huku[4].x = 150;
	pt_huku[4].y = 250;

	pt_huku[5].x = 175;
	pt_huku[5].y = 350;

	pt_huku[6].x = 200;
	pt_huku[6].y = 250;
	//--------------------

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, pt_huku[0].x, pt_huku[0].y, NULL);

	//�A�����ĕ����̐���`�悷��
	PolyPolyline(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		pt_huku,			//POINT�\���̔z��̃|�C���^
		split,				//�����𕪂���
		LINE_HUKU_CNT);		//�`�悷����̐�
}

//########## �}�`��`�悷��֐� ##########
VOID MY_DRAW_GRAPH(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//�l�p��`��
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̍��W��ݒ�
	RECT rect_sq = {
		150,150,	//����̍��W
		350,350		//�E���̍��W
	};

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�l�p��`��
	Rectangle(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_sq.left,		//�l�p�̍����X���W
		rect_sq.top,		//�l�p�̍����Y���W
		rect_sq.right,		//�l�p�̉E����X���W
		rect_sq.bottom);	//�l�p�̉E����Y���W

							//++++++++++++++++++++++++++++++++++++++++
							//�p���ۂ��l�p��`��
							//++++++++++++++++++++++++++++++++++++++++

							//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�l�p��`��
	RoundRect(
		hdc,					//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_sq.left + 10,		//�l�p�̍����X���W
		rect_sq.top + 10,		//�l�p�̍����Y���W
		rect_sq.right - 10,		//�l�p�̉E����X���W
		rect_sq.bottom - 10,	//�l�p�̉E����Y���W
		50,						//�p�̊ۂ݂̉���
		50);					//�p�̊ۂ݂̏c��

								//++++++++++++++++++++++++++++++++++++++++
								//�ȉ~��`��
								//++++++++++++++++++++++++++++++++++++++++

								//�}�`�̍��W��ݒ�
	RECT rect_eli = {
		180,180,	//����̍��W
		320,320		//�E���̍��W
	};

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�ȉ~��`��
	Ellipse(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_eli.left,		//�ȉ~�̍����X���W
		rect_eli.top,		//�ȉ~�̍����Y���W
		rect_eli.right,		//�ȉ~�̉E����X���W
		rect_eli.bottom);	//�ȉ~�̉E����Y���W

							//++++++++++++++++++++++++++++++++++++++++
							//�ʂ�`��
							//++++++++++++++++++++++++++++++++++++++++

							//�ȉ~�̔��a���擾
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//�ȉ~�̒��S���擾
	POINT chusin = {
		rect_eli.left + hankei,	// X���W
		rect_eli.top + hankei	// Y���W
	};

	//�ʂ̎n�_�̍��W
	POINT pt_ko_start = {
		chusin.x + hankei * cos(MY_PI / 4 * 0),
		chusin.y + hankei * sin(MY_PI / 4 * 0) };

	//�ʂ̏I�_�̍��W
	POINT pt_ko_end = {
		chusin.x + hankei * cos(MY_PI / 4 * 2),
		chusin.y + hankei * sin(MY_PI / 4 * 2) };

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�ʂ�`��
	Arc(
		hdc,
		rect_eli.left + 10,		//�~�̍����X���W
		rect_eli.top + 10,		//�~�̍����Y���W
		rect_eli.right - 10,	//�~�̉E����X���W
		rect_eli.bottom - 10,	//�~�̉E����Y���W
		pt_ko_start.x,			//�ʂ̎n�_��X���W
		pt_ko_start.y,			//�ʂ̎n�_��Y���W
		pt_ko_end.x,			//�ʂ̏I�_��X���W
		pt_ko_end.y);			//�ʂ̏I�_��Y���W

								//�|�`��`��
	Chord(
		hdc,
		rect_eli.left + 10,		//�~�̍����X���W
		rect_eli.top + 10,		//�~�̍����Y���W
		rect_eli.right - 10,	//�~�̉E����X���W
		rect_eli.bottom - 10,	//�~�̉E����Y���W
		pt_ko_start.x,			//�ʂ̎n�_��X���W
		pt_ko_start.y,			//�ʂ̎n�_��Y���W
		pt_ko_end.x,			//�ʂ̏I�_��X���W
		pt_ko_end.y);			//�ʂ̏I�_��Y���W

								//��`��`��
	Pie(
		hdc,
		rect_eli.left + 10,		//�~�̍����X���W
		rect_eli.top + 10,		//�~�̍����Y���W
		rect_eli.right - 10,	//�~�̉E����X���W
		rect_eli.bottom - 10,	//�~�̉E����Y���W
		pt_ko_start.x,			//�ʂ̎n�_��X���W
		pt_ko_start.y,			//�ʂ̎n�_��Y���W
		pt_ko_end.x,			//�ʂ̏I�_��X���W
		pt_ko_end.y);			//�ʂ̏I�_��Y���W

}

//########## �y�����g�p���ĕ`�悷��֐� ##########
VOID MY_DRAW_PEN(HDC hdc)
{
	//�y���F���������F�A�����Ȃǂ�ݒ�
	HPEN hpen;

	//�y�����쐬
	hpen = CreatePen(
		PS_SOLID,			//�y���̃^�C�v
		5,					//�y���̑���
		RGB(255, 0, 0));	//�y���̐F

							//�y���̃^�C�v
							//PS_SOLID		�����̃y��
							//PS_DASH		�j���̃y��
							//PS_DOT		�_���̃y��
							//PS_DASHDOT	��_�����̃y��
							//PS_DASHDOTDOT	��_�����̃y��

							//�y����ݒ�
	SelectObject(hdc, hpen);

	//�}�`�̍��W��ݒ�
	RECT rect_sq = {
		50,50,		//����̍��W
		100,100		//�E���̍��W
	};

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�l�p��`��
	Rectangle(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_sq.left,		//�l�p�̍����X���W
		rect_sq.top,		//�l�p�̍����Y���W
		rect_sq.right,		//�l�p�̉E����X���W
		rect_sq.bottom);	//�l�p�̉E����Y���W

							//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//�y�����폜
	DeleteObject(hpen);
}

//########## �u���V���g�p���ĕ`�悷��֐� ##########
VOID MY_DRAW_BRUSH(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//�ʏ�̓h��Ԃ�
	//++++++++++++++++++++++++++++++++++++++++

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush;

	//�u���V���쐬
	hbrush = CreateSolidBrush(
		RGB(255, 0, 0));//�u���V�̐F

						//�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//�}�`�̍��W��ݒ�
	RECT rect_sq = {
		150,50,		//����̍��W
		200,100		//�E���̍��W
	};

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�l�p��`��
	Rectangle(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_sq.left,		//�l�p�̍����X���W
		rect_sq.top,		//�l�p�̍����Y���W
		rect_sq.right,		//�l�p�̉E����X���W
		rect_sq.bottom);	//�l�p�̉E����Y���W

							//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//�͗l�œh��Ԃ�
	//++++++++++++++++++++++++++++++++++++++++

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush_2;

	//�u���V���쐬
	hbrush_2 = CreateHatchBrush(
		HS_CROSS,			//�u���V�̖͗l
		RGB(255, 0, 0));	//�u���V�̐F

							//�u���V�̖͗l
							//HS_BDIAGONAL	45 �x�̉E������̃n�b�`
							//HS_CROSS		�����Ɛ����̃N���X�n�b�`
							//HS_DIAGCROSS	45 �x�̃N���X�n�b�`
							//HS_FDIAGONAL	45 �x�̉E�オ��̃n�b�`
							//HS_HORIZONTAL	�����n�b�`
							//HS_VERTICAL	�����n�b�`

							//�u���V��ݒ�
	SelectObject(hdc, hbrush_2);

	//�}�`�̍��W��ݒ�
	RECT rect_sq_2 = {
		250,50,		//����̍��W
		300,100		//�E���̍��W
	};

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//�l�p��`��
	Rectangle(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_sq_2.left,		//�l�p�̍����X���W
		rect_sq_2.top,		//�l�p�̍����Y���W
		rect_sq_2.right,		//�l�p�̉E����X���W
		rect_sq_2.bottom);	//�l�p�̉E����Y���W

							//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush_2);

}

//########## ���p�`�̓h��Ԃ��ĕ`�悷��֐� ##########
VOID MY_DRAW_POLYGON(HDC hdc)
{

	//�y���F���������F�A�����Ȃǂ�ݒ�
	HPEN hpen;

	//�y�����쐬
	hpen = CreatePen(
		PS_SOLID,			//�y���̃^�C�v
		1,					//�y���̑���
		RGB(0, 0, 0));		//�y���̐F

							//�y����ݒ�
	SelectObject(hdc, hpen);

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush;

	//�u���V���쐬
	hbrush = CreateSolidBrush(
		RGB(255, 0, 0));//�u���V�̐F

						//�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//�܊p�`��`��
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̒��S��ݒ�
	POINT chusin;
	chusin.x = 200;
	chusin.y = 200;

	//�}�`�̑傫����ݒ�
	int scale = 100;

	//���p�`�̒��_�̐�
	int kaku_cnt = 5;

	//���W��ݒ�
	POINT rect_po[CHOTEN_MAX];

	//���W��90�x����](90�x�E��]�̓�/2)
	double left90 = -MY_PI / 2;

	//���W���v�Z
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//X�̍��W=���S��X���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Y�̍��W=���S��Y���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//�Ō�̍��W�͈�ԍŏ��̍��W
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//���p�`�̒������ׂēh��Ԃ�
	SetPolyFillMode(hdc, WINDING);

	//���p�`�̓h��Ԃ�
	Polygon(
		hdc,		//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_po,	//���p�`�̍��W
		kaku_cnt);	//���p�`�̒��_�̐�

					//++++++++++++++++++++++++++++++++++++++++
					//����`��
					//++++++++++++++++++++++++++++++++++++++++

					//���S��ݒ�
	chusin.x = 400;
	chusin.y = 200;

	//���W���v�Z
	for (i = 0; i < kaku_cnt; i++)
	{
		//X�̍��W=���S��X���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Y�̍��W=���S��Y���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//�Ō�̍��W�͈�ԍŏ��̍��W
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//���̍��W
	POINT rect_star[CHOTEN_MAX];

	//���������Ƃ��̏��������Q�l�ɂ���
	rect_star[0].x = rect_po[0].x;
	rect_star[0].y = rect_po[0].y;

	rect_star[1].x = rect_po[2].x;
	rect_star[1].y = rect_po[2].y;

	rect_star[2].x = rect_po[4].x;
	rect_star[2].y = rect_po[4].y;

	rect_star[3].x = rect_po[1].x;
	rect_star[3].y = rect_po[1].y;

	rect_star[4].x = rect_po[3].x;
	rect_star[4].y = rect_po[3].y;

	rect_star[5].x = rect_po[0].x;
	rect_star[5].y = rect_po[0].y;

	//���p�`�̒��Ő����������Ă���Ƃ���͓h��Ԃ��Ȃ�
	SetPolyFillMode(hdc, ALTERNATE);

	//���p�`�̓h��Ԃ�
	Polygon(
		hdc,		//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_star,	//���p�`�̍��W
		kaku_cnt);	//���p�`�̒��_�̐�

					//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

	//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//�y�����폜
	DeleteObject(hpen);
}

//########## �����̑��p�`�̓h��Ԃ��ĕ`�悷��֐� ##########
VOID MY_DRAW_POLYPOLYGON(HDC hdc)
{
	//�y���F���������F�A�����Ȃǂ�ݒ�
	HPEN hpen;

	//�y�����쐬
	hpen = CreatePen(
		PS_SOLID,			//�y���̃^�C�v
		1,					//�y���̑���
		RGB(176, 224, 230));	//�y���̐F

								//�y����ݒ�
	SelectObject(hdc, hpen);

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush;

	//�u���V���쐬
	hbrush = CreateSolidBrush(
		RGB(176, 224, 230));//�u���V�̐F

							//�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//�Z䊐���`��
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̒��S��ݒ�
	POINT chusin;
	chusin.x = 400;
	chusin.y = 400;

	//�}�`�̑傫����ݒ�
	int scale = 100;

	//���p�`�̒��_�̐�
	int kaku_cnt = 6;

	//���W��ݒ�
	POINT rect_po[CHOTEN_MAX];

	//���W��90�x����](90�x�E��]�̓�/2)
	double left90 = -MY_PI / 2;

	//���W���v�Z
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//X�̍��W=���S��X���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Y�̍��W=���S��Y���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//�Ō�̍��W�͈�ԍŏ��̍��W
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//�����̑��p�`�̒��_�̋�؂�
	int split[2]{ 3,3 };

	//�Z䊐��̍��W
	POINT rect_star[CHOTEN_MAX];

	//�Z䊐��������Ƃ��̏��������Q�l�ɂ���
	rect_star[0].x = rect_po[0].x;
	rect_star[0].y = rect_po[0].y;

	rect_star[1].x = rect_po[2].x;
	rect_star[1].y = rect_po[2].y;

	rect_star[2].x = rect_po[4].x;
	rect_star[2].y = rect_po[4].y;
	//------------------------------
	rect_star[3].x = rect_po[1].x;
	rect_star[3].y = rect_po[1].y;

	rect_star[4].x = rect_po[3].x;
	rect_star[4].y = rect_po[3].y;

	rect_star[5].x = rect_po[5].x;
	rect_star[5].y = rect_po[5].y;
	//------------------------------

	//���p�`�̒��Ő����������Ă���Ƃ���͓h��Ԃ��Ȃ�
	SetPolyFillMode(hdc, WINDING);

	//���p�`�̓h��Ԃ�
	PolyPolygon(
		hdc,		//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_star,	//���p�`�̍��W
		split,		//�����̑��p�`�̒��_�̋�؂�
		2);			//���p�`�̑���

					//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

	//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//�y�����폜
	DeleteObject(hpen);
}

//########## �p�b�N�}����`�悷��֐� ##########
VOID MY_DRAW_PACMAN(HDC hdc)
{
	//�y���F���������F�A�����Ȃǂ�ݒ�
	HPEN hpen;

	//�y�����쐬
	hpen = CreatePen(
		PS_SOLID,			//�y���̃^�C�v
		1,					//�y���̑���
		RGB(0, 0, 0));		//�y���̐F

							//�y����ݒ�
	SelectObject(hdc, hpen);

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush;

	//�u���V���쐬
	hbrush = CreateSolidBrush(
		RGB(255, 255, 0));//�u���V�̐F

						  //�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//���W��90�x����](90�x�E��]�̓�/2)
	double left90 = -MY_PI / 2;

	//++++++++++++++++++++++++++++++++++++++++
	//�ʂ�`��
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̍��W��ݒ�
	RECT rect_eli = {
		200,200,	//����̍��W
		300,300		//�E���̍��W
	};

	//�ȉ~�̔��a���擾
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//�ȉ~�̒��S���擾
	POINT chusin = {
		rect_eli.left + hankei,	// X���W
		rect_eli.top + hankei	// Y���W
	};

	//�ʂ̎n�_�̍��W
	POINT pt_ko_start = {
		chusin.x + hankei * cos(2 * MY_PI / 8 * 1 + left90),
		chusin.y + hankei * sin(2 * MY_PI / 8 * 1 + left90) };

	//�ʂ̏I�_�̍��W
	POINT pt_ko_end = {
		chusin.x + hankei * cos(2 * MY_PI / 8 * 3 + left90),
		chusin.y + hankei * sin(2 * MY_PI / 8 * 3 + left90) };

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//��`��`��
	Pie(
		hdc,
		rect_eli.left,		//�~�̍����X���W
		rect_eli.top,		//�~�̍����Y���W
		rect_eli.right,		//�~�̉E����X���W
		rect_eli.bottom,	//�~�̉E����Y���W
		pt_ko_start.x,		//�ʂ̎n�_��X���W
		pt_ko_start.y,		//�ʂ̎n�_��Y���W
		pt_ko_end.x,		//�ʂ̏I�_��X���W
		pt_ko_end.y);		//�ʂ̏I�_��Y���W

							//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

	//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//�y�����폜
	DeleteObject(hpen);
}

//########## �Z�p�`��`�悷��֐� ##########
VOID MY_DRAW_PENTAGON(HDC hdc)
{
	//�y���F���������F�A�����Ȃǂ�ݒ�
	HPEN hpen;

	//�y�����쐬
	hpen = CreatePen(
		PS_SOLID,			//�y���̃^�C�v
		1,					//�y���̑���
		RGB(0, 0, 0));		//�y���̐F

							//�y����ݒ�
	SelectObject(hdc, hpen);

	//�u���V�F�h��Ԃ��F�A�͗l�Ȃǂ�ݒ�
	HBRUSH hbrush;

	//�u���V���쐬
	hbrush = CreateSolidBrush(
		RGB(0, 128, 0));//�u���V�̐F

						//�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//�Z�p�`��`��
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̒��S��ݒ�
	POINT chusin;
	chusin.x = 100;
	chusin.y = 250;

	//�}�`�̑傫����ݒ�
	int scale = 70;

	//���p�`�̒��_�̐�
	int kaku_cnt = 6;

	//���W��ݒ�
	POINT rect_po[CHOTEN_MAX];

	//���W��90�x����](90�x�E��]�̓�/2)
	double left90 = -MY_PI / 2;

	//���W���v�Z
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//X�̍��W=���S��X���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Y�̍��W=���S��Y���W+�傫��*�ʓx(360�x/�}�`�̊p�̐�*�E���ŉ��Ԗڂ̊p+90�x����])
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//�Ō�̍��W�͈�ԍŏ��̍��W
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//���p�`�̒������ׂēh��Ԃ�
	SetPolyFillMode(hdc, WINDING);

	//���p�`�̓h��Ԃ�
	Polygon(
		hdc,		//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_po,	//���p�`�̍��W
		kaku_cnt);	//���p�`�̒��_�̐�

					//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

	//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//�y�����폜
	DeleteObject(hpen);
}

//########## �����X�^�[�{�[����`�悷��֐� ##########
VOID MY_DRAW_MONBALL(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//�y���ƃu���V���쐬
	//++++++++++++++++++++++++++++++++++++++++

	//�y�����쐬
	HPEN hpen_Black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	//�y�����쐬
	HPEN hpen_Black_Bold = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));

	//�y����ݒ�
	SelectObject(hdc, hpen_Black_Bold);

	//�u���V���쐬
	HBRUSH hbrush_Red = CreateSolidBrush(RGB(255, 0, 0));

	//�u���V���쐬
	HBRUSH hbrush_White = CreateSolidBrush(RGB(255, 255, 255));

	//�u���V��ݒ�
	SelectObject(hdc, hbrush_White);

	//++++++++++++++++++++++++++++++++++++++++
	//�}�`�̏���ݒ�
	//++++++++++++++++++++++++++++++++++++++++

	//�}�`�̍��W��ݒ�
	RECT rect_eli = {
		300,200,	//����̍��W
		400,300		//�E���̍��W
	};

	//�ȉ~�̔��a���擾
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//�ȉ~�̒��S���擾
	POINT chusin = {
		rect_eli.left + hankei,	// X���W
		rect_eli.top + hankei	// Y���W
	};

	//���W��90�x����](90�x�E��]�̓�/2)
	double left90 = -MY_PI / 2;

	//++++++++++++++++++++++++++++++++++++++++
	//��̐Ԃ�������`��
	//++++++++++++++++++++++++++++++++++++++++

	//�y����ݒ�
	SelectObject(hdc, hpen_Black_Bold);

	//�u���V��ݒ�
	SelectObject(hdc, hbrush_Red);

	//�ʂ̎n�_�̍��W
	POINT pt_ko_start;

	//�ʂ̏I�_�̍��W
	POINT pt_ko_end;

	//�ʂ̎n�_�̍��W
	pt_ko_start.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 2 + left90);
	pt_ko_start.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 2 + left90);

	//�ʂ̏I�_�̍��W
	pt_ko_end.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 6 + left90);
	pt_ko_end.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 6 + left90);

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//��`��`��
	Pie(
		hdc,
		rect_eli.left,		//�~�̍����X���W
		rect_eli.top,		//�~�̍����Y���W
		rect_eli.right,		//�~�̉E����X���W
		rect_eli.bottom,	//�~�̉E����Y���W
		pt_ko_start.x,		//�ʂ̎n�_��X���W
		pt_ko_start.y,		//�ʂ̎n�_��Y���W
		pt_ko_end.x,		//�ʂ̏I�_��X���W
		pt_ko_end.y);		//�ʂ̏I�_��Y���W

							//++++++++++++++++++++++++++++++++++++++++
							//���̔���������`��
							//++++++++++++++++++++++++++++++++++++++++

							//�y����ݒ�
	SelectObject(hdc, hpen_Black_Bold);

	//�u���V��ݒ�
	SelectObject(hdc, hbrush_White);

	//�ʂ̎n�_�̍��W
	pt_ko_start.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 6 + left90);
	pt_ko_start.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 6 + left90);

	//�ʂ̏I�_�̍��W
	pt_ko_end.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 2 + left90);
	pt_ko_end.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 2 + left90);

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//��`��`��
	Pie(
		hdc,
		rect_eli.left,		//�~�̍����X���W
		rect_eli.top,		//�~�̍����Y���W
		rect_eli.right,		//�~�̉E����X���W
		rect_eli.bottom,	//�~�̉E����Y���W
		pt_ko_start.x,		//�ʂ̎n�_��X���W
		pt_ko_start.y,		//�ʂ̎n�_��Y���W
		pt_ko_end.x,		//�ʂ̏I�_��X���W
		pt_ko_end.y);		//�ʂ̏I�_��Y���W

							//++++++++++++++++++++++++++++++++++++++++
							//�^�񒆂̊ۂ��{�^����`��
							//++++++++++++++++++++++++++++++++++++++++

							//�y����ݒ�
	SelectObject(hdc, hpen_Black_Bold);

	//�u���V��ݒ�
	SelectObject(hdc, hbrush_White);

	//�}�`�̍��W��ݒ�
	RECT rect_circle;
	rect_circle.left = rect_eli.left + 35;
	rect_circle.top = rect_eli.top + 35;
	rect_circle.right = rect_eli.right - 35;
	rect_circle.bottom = rect_eli.bottom - 35;

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_circle.left, rect_circle.top, NULL);

	//�ȉ~��`��
	Ellipse(
		hdc,
		rect_circle.left,
		rect_circle.top,
		rect_circle.right,
		rect_circle.bottom);

	//++++++++++++++++++++++++++++++++++++++++
	//�^�񒆂̊ۂ��{�^���̒��̃{�^����`��
	//++++++++++++++++++++++++++++++++++++++++

	//�y����ݒ�
	SelectObject(hdc, hpen_Black);

	//�u���V��ݒ�
	SelectObject(hdc, hbrush_White);

	//�}�`�̍��W��ݒ�
	RECT rect_circle_button;
	rect_circle_button.left = rect_eli.left + 42;
	rect_circle_button.top = rect_eli.top + 42;
	rect_circle_button.right = rect_eli.right - 42;
	rect_circle_button.bottom = rect_eli.bottom - 42;

	//�����ǂ�����`���n�߂邩�ݒ肷��
	MoveToEx(hdc, rect_circle_button.left, rect_circle_button.top, NULL);

	//�ȉ~��`��
	Ellipse(
		hdc,
		rect_circle_button.left,
		rect_circle_button.top,
		rect_circle_button.right,
		rect_circle_button.bottom);

	//++++++++++++++++++++++++++++++++++++++++
	//�y���ƃu���V���f�t�H���g�ɖ߂�
	//++++++++++++++++++++++++++++++++++++++++

	//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�y�����f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//++++++++++++++++++++++++++++++++++++++++
	//�y���ƃu���V���폜
	//++++++++++++++++++++++++++++++++++++++++

	//�u���V���폜
	DeleteObject(hbrush_Red);

	//�u���V���폜
	DeleteObject(hbrush_White);

	//�y�����폜
	DeleteObject(hpen_Black);

	//�y�����폜
	DeleteObject(hpen_Black_Bold);

}

//########## �r�b�g�}�b�v��`�悷��֐� ##########
VOID MY_DRAW_BITMAP(HDC hdc)
{

	//�u���V���쐬
	HBRUSH hbrush = CreateSolidBrush(RGB(128, 128, 0));

	//�u���V��ݒ�
	SelectObject(hdc, hbrush);

	//�l�p��`��
	Rectangle(
		hdc,			//�f�o�C�X�R���e�L�X�g�̃n���h��
		rect_c.left,	//�l�p�̍����X���W
		rect_c.top,		//�l�p�̍����Y���W
		rect_c.right,	//�l�p�̉E����X���W
		rect_c.bottom);	//�l�p�̉E����Y���W

						//�w�i�F���w�肵�ĕ`��
	TransparentBlt(
		hdc,				//�`�悷��f�o�C�X�R���e�L�X�g
		bmp_dragon.x,		//�`��J�n�ʒuX���W
		bmp_dragon.y,		//�`��J�n�ʒuY���W
		bmp_dragon.width,	//�`�悷�镝
		bmp_dragon.height,	//�`�悷�鍂��
		bmp_dragon.mhdc,	//�r�b�g�}�b�v�̃f�o�C�X�R���e�L�X�g
		0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(Y���W)
		bmp_dragon.width,	//�r�b�g�}�b�v���ǂ��܂ŃR�s�[���邩(X���W)
		bmp_dragon.height,	//�r�b�g�}�b�v���ǂ��܂ŃR�s�[���邩(Y���W)
		GetPixel(bmp_dragon.mhdc, 0, 0));//���ߐF���w��


		//�R�����g�A�E�g

		////+++++�r�b�g�}�b�v��`��++++++++++++++++++++

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon.x = 100;
		//bmp_dragon.y = 100;

		////�r�b�g�}�b�v��`��
		//BitBlt(
		//	hdc,				//�`�悷��f�o�C�X�R���e�L�X�g
		//	bmp_dragon.x,		//�`��J�n�ʒuX���W
		//	bmp_dragon.y,		//�`��J�n�ʒuY���W
		//	bmp_dragon.width,	//�`�悷�镝
		//	bmp_dragon.height,	//�`�悷�鍂��
		//	bmp_dragon.mhdc,	//�r�b�g�}�b�v�̃f�o�C�X�R���e�L�X�g
		//	0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	SRCCOPY);			//�h��Ԃ��̃I�v�V����(���X�^�I�y���[�V�����R�[�h)

		////+++++�r�b�g�}�b�v�̔w�i�𓧉߂��ĕ`��(����y)++++++++++++++++++++

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon.x = 200;
		//bmp_dragon.y = 200;


		////�w�i�F���w�肵�ĕ`��
		//TransparentBlt(
		//	hdc,				//�`�悷��f�o�C�X�R���e�L�X�g
		//	bmp_dragon.x,		//�`��J�n�ʒuX���W
		//	bmp_dragon.y,		//�`��J�n�ʒuY���W
		//	bmp_dragon.width,	//�`�悷�镝
		//	bmp_dragon.height,	//�`�悷�鍂��
		//	bmp_dragon.mhdc,	//�r�b�g�}�b�v�̃f�o�C�X�R���e�L�X�g
		//	0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	0,					//�r�b�g�}�b�v���ǂ�����R�s�[���邩(Y���W)
		//	bmp_dragon.width,	//�r�b�g�}�b�v���ǂ��܂ŃR�s�[���邩(X���W)
		//	bmp_dragon.height,	//�r�b�g�}�b�v���ǂ��܂ŃR�s�[���邩(Y���W)
		//	RGB(107, 140, 148));//GetPixel(bmp_dragon.mhdc,0,0)����
		//						//+++++�r�b�g�}�b�v�̔w�i�𓧉߂��ĕ`��(�����`��)++++++++++++++++++++

		//						//�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon_mask.x = 300;
		//bmp_dragon_mask.y = 300;

		//bmp_dragon_white.x = 300;
		//bmp_dragon_white.y = 300;

		////�w�i�ƃ}�X�N��AND�œ]�����}�X�N�̍��������͖��������
		//BitBlt(
		//	hdc,						//�`�悷��f�o�C�X�R���e�L�X�g
		//	bmp_dragon_mask.x,			//�`��J�n�ʒuX���W
		//	bmp_dragon_mask.y,			//�`��J�n�ʒuY���W
		//	bmp_dragon_mask.width,		//�`�悷�镝
		//	bmp_dragon_mask.height,		//�`�悷�鍂��
		//	bmp_dragon_mask.mhdc,		//�r�b�g�}�b�v�̃f�o�C�X�R���e�L�X�g
		//	0,							//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	0,							//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	SRCPAINT);					//�h��Ԃ��̃I�v�V����(���X�^�I�y���[�V�����R�[�h)

		//								//�w�i�ƃr�b�g�}�b�v��OR�œ]�����r�b�g�}�b�v�̔����w�i�͖��������
		//BitBlt(
		//	hdc,						//�`�悷��f�o�C�X�R���e�L�X�g
		//	bmp_dragon_white.x,			//�`��J�n�ʒuX���W
		//	bmp_dragon_white.y,			//�`��J�n�ʒuY���W
		//	bmp_dragon_white.width,		//�`�悷�镝
		//	bmp_dragon_white.height,	//�`�悷�鍂��
		//	bmp_dragon_white.mhdc,		//�r�b�g�}�b�v�̃f�o�C�X�R���e�L�X�g
		//	0,							//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	0,							//�r�b�g�}�b�v���ǂ�����R�s�[���邩(X���W)
		//	SRCAND);					//�h��Ԃ��̃I�v�V����(���X�^�I�y���[�V�����R�[�h)

		////+++++ �摜�̊g��E�k�� ++++++++++++++++++++

		////�g��k����(�{)
		//double rate = 2.0;

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon.x = 50;
		//bmp_dragon.y = 250;

		////�X�g���b�`���[�h���w��
		//SetStretchBltMode(hdc, COLORONCOLOR);

		////�X�g���b�`���[�h�̎��
		////BLACKONWHITE	�c���_�̐F�Ǝ�菜���_�̐F��_�� AND ���Z�q�Ō���
		////COLORONCOLOR	��菜���_�̏���ۑ����邱�ƂȂ��A�폜���܂�
		////HALFTONE		�R�s�[��̃u���b�N�̕��ϓI�ȐF���A�R�s�[���̃s�N�Z���̐F�ɋ߂��F
		////				HALFTONE���[�h��ݒ肵���ꍇ�́A�u���V�̂����h������
		////				SetBrushOrgEx() �֐����Ăяo��
		////WHITEONBLACK	�c���_�̐F�Ǝ�菜���_�̐F��_�� OR ���Z�q�Ō���
		////STRETCH_ANDSCANS		BLACKONWHITE �Ɠ���
		////STRETCH_DELETESCANS	COLORONCOLOR �Ɠ����ł�
		////STRETCH_HALFTONE		HALFTONE �Ɠ����ł�
		////STRETCH_ORSCANS		WHITEONBLACK �Ɠ����ł�

		//StretchBlt(
		//	hdc,					//�R�s�[��̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	bmp_dragon.x,			//�R�s�[��̒����`�̍��� X���W
		//	bmp_dragon.y,			//�R�s�[��̒����`�̍��� Y���W
		//	bmp_dragon.width*rate,	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.height*rate,	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.mhdc,		//�R�s�[���̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	0,						//�R�s�[���̒����`�̍��� X���W
		//	0,						//�R�s�[���̒����`�̍��� Y���W
		//	bmp_dragon.width,		//�R�s�[���̒����`�̉E�� X���W
		//	bmp_dragon.height,		//�R�s�[���̒����`�̍��� Y���W
		//	SRCCOPY					//���X�^�I�y���[�V�������w��
		//);

		////+++++ �摜�𔽓]������ ++++++++++++++++++++

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon.x = 400;
		//bmp_dragon.y = 400;

		////�g��k����
		//rate = 0.75;

		////�R�s�[��̒����`�̉E���̍��W�ɁA�}�C�i�X��t������Ɣ��]����
		////���E���]
		//StretchBlt(
		//	hdc,						//�R�s�[��̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	bmp_dragon.x,				//�R�s�[��̒����`�̍��� X���W
		//	bmp_dragon.y,				//�R�s�[��̒����`�̍��� Y���W
		//	-(bmp_dragon.width*rate),	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.height*rate,		//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.mhdc,			//�R�s�[���̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	0,							//�R�s�[���̒����`�̍��� X���W
		//	0,							//�R�s�[���̒����`�̍��� Y���W
		//	bmp_dragon.width,			//�R�s�[���̒����`�̉E�� X���W
		//	bmp_dragon.height,			//�R�s�[���̒����`�̍��� Y���W
		//	SRCCOPY						//���X�^�I�y���[�V�������w��
		//);

		////+++++ �������ȉ摜��\�������� ++++++++++++++++++++

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon.x = 350;
		//bmp_dragon.y = 100;

		////�g��k����
		//rate = 2.0;

		//BLENDFUNCTION bf;	//�u�����h�t�@���N�V�����\����

		//bf.BlendOp = AC_SRC_OVER;		//AC_SRC_OVER�̂�
		//bf.BlendFlags = 0;				//�[���̂�
		//bf.AlphaFormat = AC_SRC_ALPHA;	//�r�b�g�}�b�v�̃A���t�@�`���l�����g�p
		//bf.SourceConstantAlpha = 100;	//�����ɂ��銄��(�����F0�`255�F�s����)

		//								//�������ŕ\��
		//AlphaBlend(
		//	hdc,						//�R�s�[��̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	bmp_dragon.x,				//�R�s�[��̒����`�̍��� X���W
		//	bmp_dragon.y,				//�R�s�[��̒����`�̍��� Y���W
		//	bmp_dragon.width *rate,		//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.height*rate,		//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon.mhdc,			//�R�s�[���̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	0,							//�R�s�[���̒����`�̍��� X���W
		//	0,							//�R�s�[���̒����`�̍��� Y���W
		//	bmp_dragon.width,			//�R�s�[���̒����`�̉E�� X���W
		//	bmp_dragon.height,			//�R�s�[���̒����`�̍��� Y���W
		//	bf							//�u�����h�t�@���N�V�����\����
		//);

		////+++++ �摜�̔w�i�𓧉߂��Ċg��E�k�� ++++++++++++++++++++

		////�r�b�g�}�b�v�̕\���ʒu��ݒ�
		//bmp_dragon_mask.x = 250;
		//bmp_dragon_mask.y = 350;

		//bmp_dragon_white.x = 250;
		//bmp_dragon_white.y = 350;

		////�g��k����
		//rate = 1.50;

		////�w�i�ƃ}�X�N��AND�œ]�����}�X�N�̍��������͖��������
		//StretchBlt(
		//	hdc,							//�R�s�[��̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	bmp_dragon_mask.x,				//�R�s�[��̒����`�̍��� X���W
		//	bmp_dragon_mask.y,				//�R�s�[��̒����`�̍��� Y���W
		//	-(bmp_dragon_mask.width*rate),	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon_mask.height*rate,	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon_mask.mhdc,			//�R�s�[���̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	0,								//�R�s�[���̒����`�̍��� X���W
		//	0,								//�R�s�[���̒����`�̍��� Y���W
		//	bmp_dragon_mask.width,			//�R�s�[���̒����`�̉E�� X���W
		//	bmp_dragon_mask.height,			//�R�s�[���̒����`�̍��� Y���W
		//	SRCPAINT						//���X�^�I�y���[�V�������w��
		//);

		////�w�i�ƃr�b�g�}�b�v��OR�œ]�����r�b�g�}�b�v�̔����w�i�͖��������
		//StretchBlt(
		//	hdc,							//�R�s�[��̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	bmp_dragon_white.x,				//�R�s�[��̒����`�̍��� X���W
		//	bmp_dragon_white.y,				//�R�s�[��̒����`�̍��� Y���W
		//	-(bmp_dragon_white.width*rate),	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon_white.height*rate,	//�R�s�[��̒����`�̉E�� X���W
		//	bmp_dragon_white.mhdc,			//�R�s�[���̃f�o�C�X�R���e�L�X�g�̃n���h��
		//	0,								//�R�s�[���̒����`�̍��� X���W
		//	0,								//�R�s�[���̒����`�̍��� Y���W
		//	bmp_dragon_white.width,			//�R�s�[���̒����`�̉E�� X���W
		//	bmp_dragon_white.height,		//�R�s�[���̒����`�̍��� Y���W
		//	SRCAND							//���X�^�I�y���[�V�������w��
		//);

	//�u���V���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//�u���V���폜
	DeleteObject(hbrush);

}

//########## �ǂ̃L�[�������Ă��邩���肷��֐� ##########
VOID MY_CHECK_KEYDOWN(VOID)
{

	//���������� MY_CHECK_KEYDOWN���C�� ����������

	//GetKeyboardState()�֐�
	//�����Ƃ��āABYTE�^�̔z��(256��)���󂯎��
	//���ׂẲ��z�L�[�̌��݂̏�Ԃ���x�Ɏ擾����
	//�ŏ�ʃr�b�g�� 1 �̂Ƃ��̓L�[��������Ă���
	//               0 �̂Ƃ��̓L�[��������Ă��Ȃ�

	//�ŉ��ʃr�b�g�� 1 �̂Ƃ��̓L�[���g�O����Ԃɂ���
	//               0 �̂Ƃ��̓g�O������������Ă���
	//���Ƃ��΁ACapsLock �L�[�� ON �ɂȂ��Ă���Ƃ��́A�g�O����ԂɂȂ�B

	//���ׂẲ��z�L�[�̌��݂̏�Ԃ���C�Ɏ擾����
	GetKeyboardState(KeyBoard);

	//���z�L�[�R�[�h�ŁAA�`Z�A0�`9�́AASCII�R�[�h���w��
	BYTE IskeyDown_W = KeyBoard['W'] & 0x80;
	BYTE IskeyDown_D = KeyBoard['D'] & 0x80;
	BYTE IskeyDown_A = KeyBoard['A'] & 0x80;
	BYTE IskeyDown_S = KeyBoard['S'] & 0x80;
	BYTE IsKeyDown_B = KeyBoard['B'] & 0x80;
	BYTE IsKeyDown_P = KeyBoard['P'] & 0x80;

	//W�L�[��������Ă��邩���肷��
	if (IskeyDown_W != 0)
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_UP;
	}

	//D�L�[��������Ă��邩���肷��
	if (IskeyDown_D != 0)
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_UP;
	}

	//S�L�[��������Ă��邩���肷��
	if (IskeyDown_S != 0)
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_UP;
	}

	//A�L�[��������Ă��邩���肷��
	if (IskeyDown_A != 0)
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_UP;
	}

	//B�L�[��������Ă��邩���肷��
	if (IsKeyDown_B != 0)
	{
		ShiftKey = MY_KEY_DOWN;
	}
	else
	{
		ShiftKey = MY_KEY_UP;
	}

	//P�L�[��������Ă��邩���肷��
	if (IsKeyDown_P != 0)
	{
		PlaySoundKey = MY_KEY_DOWN;
	}
	else
	{
		PlaySoundKey = MY_KEY_UP;
	}

	return;

	//���������� MY_CHECK_KEYDOWN���C�� ����������

	//GetKeyState		�F�L�[��������Ă��邩����
	//GetAsyncKeyState	�F�L�[��������Ă��違�O��̏����擾
	//					�F�߂�l�̍ŏ�ʃr�b�g��1(& 0x8000)�Ȃ�A������Ă���
	//					�F�߂�l�̍ŉ��ʃr�b�g��1(& 0x0001)�Ȃ�A�O�񂩂牟����Ă���
	//					�F�߂�l�@�@�@�@�@�@�@��0		   �Ȃ�A������Ă��Ȃ�

	SHORT IskeyDown_Up = GetAsyncKeyState(VK_UP) & 0x8000;
	SHORT IskeyDown_Right = GetAsyncKeyState(VK_RIGHT) & 0x8000;
	SHORT IskeyDown_Down = GetAsyncKeyState(VK_DOWN) & 0x8000;
	SHORT IskeyDown_Left = GetAsyncKeyState(VK_LEFT) & 0x8000;
	SHORT IsKeyDown_Shift = GetAsyncKeyState(VK_SHIFT) & 0x8000;

	//����L�[��������Ă��邩���肷��
	if (IskeyDown_Up != 0)
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_UP;
	}

	//�E���L�[��������Ă��邩���肷��
	if (IskeyDown_Right != 0)
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_UP;
	}

	//�����L�[��������Ă��邩���肷��
	if (IskeyDown_Down != 0)
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_UP;
	}

	//�����L�[��������Ă��邩���肷��
	if (IskeyDown_Left != 0)
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_DOWN;
	}
	else
	{
		ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_UP;
	}

	//�V�t�g�L�[��������Ă��邩���肷��
	if (IsKeyDown_Shift != 0)
	{
		ShiftKey = MY_KEY_DOWN;
	}
	else
	{
		ShiftKey = MY_KEY_UP;
	}


	//�C���O�̃v���O�����̓R�����g�A�E�g
	////����L�[��������Ă��邩���肷��
	//if (GetKeyState(VK_UP) < 0)
	//{
	//	ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_DOWN;
	//}
	//else
	//{
	//	ArrowKey[MY_KEY_ARROW_UP] = MY_KEY_UP;
	//}

	////�E���L�[��������Ă��邩���肷��
	//if (GetKeyState(VK_RIGHT) < 0)
	//{
	//	ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_DOWN;
	//}
	//else
	//{
	//	ArrowKey[MY_KEY_ARROW_RIGHT] = MY_KEY_UP;
	//}

	////�����L�[��������Ă��邩���肷��
	//if (GetKeyState(VK_DOWN) < 0)
	//{
	//	ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_DOWN;
	//}
	//else
	//{
	//	ArrowKey[MY_KEY_ARROW_DOWN] = MY_KEY_UP;
	//}

	////�����L�[��������Ă��邩���肷��
	//if (GetKeyState(VK_LEFT) < 0)
	//{
	//	ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_DOWN;
	//}
	//else
	//{
	//	ArrowKey[MY_KEY_ARROW_LEFT] = MY_KEY_UP;
	//}

	////�V�t�g�L�[��������Ă��邩���肷��
	//if (GetKeyState(VK_SHIFT) < 0)
	//{
	//	ShiftKey = MY_KEY_DOWN;
	//}
	//else
	//{
	//	ShiftKey = MY_KEY_UP;
	//}

}

//########## �r�b�g�}�b�v���ړ�������֐� ##########
VOID MY_MOVE_BITMAP(MY_BMP *bmp)
{

	//�V�t�g�L�[��������Ă���Ƃ��͑���������
	if (ShiftKey == MY_KEY_DOWN)
	{
		Speed = MY_SPEED_METEOR;
	}
	else
	{
		Speed = MY_SPEED_NORMAL;
	}

	//����L�[��������Ă���Ώ�ɓ�����
	if (ArrowKey[MY_KEY_ARROW_UP] == MY_KEY_DOWN)
	{
		bmp->y -= Speed;
	}

	//�E���L�[��������Ă���ΉE�ɓ�����
	if (ArrowKey[MY_KEY_ARROW_RIGHT] == MY_KEY_DOWN)
	{
		bmp->x += Speed;
	}

	//�����L�[��������Ă���Ή��ɓ�����
	if (ArrowKey[MY_KEY_ARROW_DOWN] == MY_KEY_DOWN)
	{
		bmp->y += Speed;
	}

	//�����L�[��������Ă���΍��ɓ�����
	if (ArrowKey[MY_KEY_ARROW_LEFT] == MY_KEY_DOWN)
	{
		bmp->x -= Speed;
	}


}

//########## �L�[�{�[�h�̉��z�L�[�R�[�h�𐮌`����֐� ##########
VOID MY_FORMAT_KEYCODE(WPARAM wp, int message)
{
	//�V�t�g�L�[�������Ă��邩���f
	if (GetKeyState(VK_SHIFT) < 0)	//�L�[��������Ă���Ƃ�
	{
		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyState, TEXT("�L�[��ԁFShift�F%0X"), wp);
	}
	//Ctrl�L�[�������Ă��邩���f
	else if (GetKeyState(VK_CONTROL) < 0)	//�L�[��������Ă���Ƃ�
	{
		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyState, TEXT("�L�[��ԁFCtrl�F%0X"), wp);
	}
	//�����Ă��Ȃ��Ƃ�
	else
	{
		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyState, TEXT("�L�[��ԁF--"), wp);
	}

	switch (message)
	{
	case WM_KEYDOWN:
		//�L�[���������Ƃ�

		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyCode, TEXT("�L�[�R�[�h�F%0X"), wp);

		break;

	case WM_KEYUP:
		//�L�[���グ���Ƃ�

		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyCode, TEXT("�L�[�R�[�h�F--"));

		break;

	case WM_SYSKEYDOWN:
		//�V�X�e���L�[���������Ƃ�

		//Alt�L�[���������Ƃ�
		if (wp == VK_MENU)
		{
			//�L�[�R�[�h�𕶎���Ƃ��Đ��`
			wsprintf(Str_KeyCode, TEXT("�V�X�e���L�[�R�[�h�FAlt�F%0X"), wp);
		}

		break;

	case WM_SYSKEYUP:
		//�V�X�e���L�[���グ���Ƃ�

		//�L�[�R�[�h�𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyCode, TEXT("�V�X�e���L�[�R�[�h�F--"));

		break;
	}
}

//########## ���z�L�[�R�[�h�𕶎��ɐ��`����֐� ##########
VOID MY_FORMAT_KEYCHAR(WPARAM wp, int message)
{

	switch (message)
	{
	case WM_CHAR:
		//�L�[�R�[�h�𕶎��ɕϊ������Ƃ�

		//�L�[�����𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyValue, TEXT("�L�[�����F%s"), (PTSTR)&wp);

		break;

	case WM_KEYUP:
		//�L�[���グ���Ƃ�

		//�L�[�����𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyValue, TEXT("�L�[�����F--"));

		break;

	case WM_SYSCHAR:
		//�L�[�R�[�h�𕶎��ɕϊ������Ƃ�

		//�L�[�����𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyValue, TEXT("�V�X�e���L�[�����F%s"), (PTSTR)&wp);

		break;

	case WM_SYSKEYUP:
		//�V�X�e���L�[���グ���Ƃ�

		//�L�[�����𕶎���Ƃ��Đ��`
		wsprintf(Str_KeyValue, TEXT("�V�X�e���L�[�����F--"));

		break;
	}
}

//########## ����炷�֐� ##########
VOID MY_SOUND(VOID)
{
	//���g���̎Q�l�T�C�g
	//https://tomari.org/main/java/oto.html
	int Doremi[7] = {
		261,
		293,
		329,
		349,
		391,
		440,
		493
	};

	//�y��
	int Gakuhu[7][2]
	{
		{ Doremi[0],500 },
		{ Doremi[1],500 },
		{ Doremi[2],500 },
		{ Doremi[3],500 },
		{ Doremi[4],500 },
		{ Doremi[5],500 },
		{ Doremi[6],500 },
	};

	//�����������Đ����郂�[�h��؂�ւ�������
	int sound_mode = 5;

	if (PlaySoundKey == MY_KEY_DOWN)
	{
		switch (sound_mode)
		{
		case 0:
			//�r�[�v����炷
			//�֐��Ăяo���ƃT�E���h�Đ��͔񓯊��I�ɍs�Ȃ���

			MessageBeep(
				-1  // �T�E���h�^�C�v
			);
			Sleep(100);

			//�T�E���h�^�C�v�̎��
			//-1						�R���s���[�^�̃X�s�[�J���甭������W���I�ȃr�[�v��
			//MB_ICONASTERISK			SystemAsterisk		���b�Z�[�W�i���j
			//MB_ICONEXCLAMATION		SystemExclamation	���b�Z�[�W�i�x���j
			//MB_ICONHAND				SystemHand			�V�X�e���G���[
			//MB_ICONQUESTION			SystemQuestion		���b�Z�[�W�i�₢���킹�j
			//MB_OK						SystemDefault		��ʂ̌x����

		case 1:
			//���g���ŉ���炷
			//�֐��Ăяo���ƃT�E���h�Đ��͓����I�ɍs�Ȃ���

			Beep(
				440,	//���̎��g�����A37�`32767�̊Ԃ̒l�Ŏw��
				1000	//����炷���Ԃ��~���b�P�ʂŎw��
			);

		case 2:
			//�y���̂悤�ɉ��t����

			int i;
			for (i = 0; i < 7; i++)
			{
				Beep(Gakuhu[i][0], Gakuhu[i][1]);
			}

			break;

		case 3:
			//wave�t�@�C�����Đ�

			//�����Đ���������̂��|�C���g�I

			PlaySound(
				SOUND_KOUKA_1,	//�Đ��Ώۂ̃T�E���h
				NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
				SND_FILENAME	//�t�@�C�����Ŏw��
				| SND_LOOP		//�T�E���h�����[�v
				| SND_ASYNC		//�T�E���h��񓯊��Đ�
			);

			//�����~����
			//PlaySound(NULL,NULL,SND_PURGE);

			break;

		case 4:
			//wave�t�@�C�����Đ�

			//�����Đ��ł��Ȃ��̂��|�C���g�I

			PlaySound(
				SOUND_KOUKA_1,	//�Đ��Ώۂ̃T�E���h
				NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
				SND_FILENAME	//�t�@�C�����Ŏw��
				| SND_LOOP		//�T�E���h�����[�v
				| SND_ASYNC		//�T�E���h��񓯊��Đ�
			);

			PlaySound(
				SOUND_KOUKA_2,	//�Đ��Ώۂ̃T�E���h
				NULL,			//�C���X�^���X�n���h��/�t�@�C���Ȃ�NULL
				SND_FILENAME	//�t�@�C�����Ŏw��
				| SND_SYNC		//�T�E���h�𓯊��Đ�
			);

			break;

		case 5:
			//mp3�t�@�C�����Đ�
			mciSendCommand(
				open1.wDeviceID, 
				MCI_PLAY, 
				MCI_NOTIFY,				//MM_MCINOTIFY���Đ��I����,���s
				(DWORD_PTR)&play1
			);

			//mp3�t�@�C�����Đ�
			mciSendCommand(
				open2.wDeviceID,
				MCI_PLAY,
				MCI_DGV_PLAY_REPEAT,	//���[�v�Đ�
				(DWORD_PTR)&play2
			);

			//wave�t�@�C�����Đ�
			mciSendCommand(
				open3.wDeviceID,
				MCI_PLAY,
				MCI_NOTIFY,				//MM_MCINOTIFY���Đ��I����,���s
				(DWORD_PTR)&play3
			);
			break;

		}
	}
}


//########## �E�B���h�E�v���V�[�W���֐� ##########
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//HDC�F�f�o�C�X�R���e�L�X�g�̃n���h��
	HDC hdc;

	//PAINTSTRUCT�F�E�B���h�E���Ƃ̕`������Ǘ�����\����
	PAINTSTRUCT ps;

	switch (msg)
	{

	case WM_CREATE:
		//�E�B���h�E�̐�����������

		//judge hard�t�H���g���ꎞ�I�ɓǂݍ���
		if (AddFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL) == 0)
		{
			//�t�H���g���ǂݍ��߂Ȃ������Ƃ�
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//���ʂ������}�W�b�N�t�H���g���ꎞ�I�ɓǂݍ���
		if (AddFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL) == 0)
		{
			//�t�H���g���ǂݍ��߂Ȃ������Ƃ�
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//+++++�h���S���̃r�b�g�}�b�v++++++++++++++++++++

		//�r�b�g�}�b�v��ǂݍ���
		bmp_dragon.hbmp =		//�r�b�g�}�b�v�̃n���h��
			(HBITMAP)LoadImage(
				NULL,			// �C���X�^���X�̃n���h��/BTMAP��ǂݍ��ޏꍇ��NULL
				BMP_DRA_PASS,	//�r�b�g�}�b�v�̏ꏊ�Ɩ��O
				IMAGE_BITMAP,	//�C���[�W�̃^�C�v
				0,				//��   /���̂܂܎g�p����ɂ�0
				0,				//���� /���̂܂܎g�p����ɂ�0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ���[�h�̃I�v�V����

														//�r�b�g�}�b�v�ǂݍ��݃G���[
		if (bmp_dragon.hbmp == NULL)
		{
			//�r�b�g�}�b�v���ǂݍ��߂Ȃ������Ƃ�
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//�摜�T�C�Y�擾
		GetObject(bmp_dragon.hbmp, sizeof(BITMAP), &bmp_dragon.bmp);
		bmp_dragon.width = bmp_dragon.bmp.bmWidth;		//�����擾
		bmp_dragon.height = bmp_dragon.bmp.bmHeight;	//�������擾

														//�������f�o�C�X�R���e�L�X�g���쐬
		bmp_dragon.mhdc = CreateCompatibleDC(NULL);

		//�������f�o�C�X�R���e�L�X�g�Ƀr�b�g�}�b�v��ݒ�
		SelectObject(bmp_dragon.mhdc, bmp_dragon.hbmp);

		//+++++�h���S���̃r�b�g�}�b�v(�w�i��)++++++++++++++++++++

		//�r�b�g�}�b�v��ǂݍ���
		bmp_dragon_white.hbmp =		//�r�b�g�}�b�v�̃n���h��
			(HBITMAP)LoadImage(
				NULL,				// �C���X�^���X�̃n���h��/BTMAP��ǂݍ��ޏꍇ��NULL
				BMP_DRA_WH_PASS,	//�r�b�g�}�b�v�̏ꏊ�Ɩ��O
				IMAGE_BITMAP,		//�C���[�W�̃^�C�v
				0,					//��   /���̂܂܎g�p����ɂ�0
				0,					//���� /���̂܂܎g�p����ɂ�0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ���[�h�̃I�v�V����

														//�r�b�g�}�b�v�ǂݍ��݃G���[
		if (bmp_dragon_white.hbmp == NULL)
		{
			//�r�b�g�}�b�v���ǂݍ��߂Ȃ������Ƃ�
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//�摜�T�C�Y�擾
		GetObject(bmp_dragon_white.hbmp, sizeof(BITMAP), &bmp_dragon_white.bmp);
		bmp_dragon_white.width = bmp_dragon_white.bmp.bmWidth;		//�����擾
		bmp_dragon_white.height = bmp_dragon_white.bmp.bmHeight;	//�������擾

																	//�������f�o�C�X�R���e�L�X�g���쐬
		bmp_dragon_white.mhdc = CreateCompatibleDC(NULL);

		//�������f�o�C�X�R���e�L�X�g�Ƀr�b�g�}�b�v��ݒ�
		SelectObject(bmp_dragon_white.mhdc, bmp_dragon_white.hbmp);

		//+++++�h���S���̃}�X�N++++++++++++++++++++

		//�r�b�g�}�b�v��ǂݍ���
		bmp_dragon_mask.hbmp =		//�r�b�g�}�b�v�̃n���h��
			(HBITMAP)LoadImage(
				NULL,				// �C���X�^���X�̃n���h��/BTMAP��ǂݍ��ޏꍇ��NULL
				BMP_DRA_MS_PASS,	//�r�b�g�}�b�v�̏ꏊ�Ɩ��O
				IMAGE_BITMAP,		//�C���[�W�̃^�C�v
				0,					//��   /���̂܂܎g�p����ɂ�0
				0,					//���� /���̂܂܎g�p����ɂ�0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ���[�h�̃I�v�V����

														//�r�b�g�}�b�v�ǂݍ��݃G���[
		if (bmp_dragon_mask.hbmp == NULL)
		{
			//�r�b�g�}�b�v���ǂݍ��߂Ȃ������Ƃ�
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//�摜�T�C�Y�擾
		GetObject(bmp_dragon_mask.hbmp, sizeof(BITMAP), &bmp_dragon_mask.bmp);
		bmp_dragon_mask.width = bmp_dragon_mask.bmp.bmWidth;		//�����擾
		bmp_dragon_mask.height = bmp_dragon_mask.bmp.bmHeight;	//�������擾

																//�������f�o�C�X�R���e�L�X�g���쐬
		bmp_dragon_mask.mhdc = CreateCompatibleDC(NULL);

		//�������f�o�C�X�R���e�L�X�g�Ƀr�b�g�}�b�v��ݒ�
		SelectObject(bmp_dragon_mask.mhdc, bmp_dragon_mask.hbmp);

		//���������� WM_CREATE�ɒǉ� ����������

		//MP3�̏���ݒ�
		open1.lpstrDeviceType = TEXT("MPEGVideo");
		open1.lpstrElementName = SOUND_BGM_MP3_1;

		//MP3���擾
		res_sound = mciSendCommand(
			0,
			MCI_OPEN, 			//�f�o�C�X���I�[�v��
			MCI_OPEN_TYPE		//MP3�t�@�C���̏ꍇ
			| MCI_OPEN_ELEMENT,	//MP3�t�@�C���̏ꍇ
			(DWORD_PTR)&open1);

		//MP3���ǂݍ��߂Ȃ������Ƃ�
		if (res_sound)
		{
			MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
		}

		//MP3�̏���ݒ�
		open2.lpstrDeviceType = TEXT("MPEGVideo");
		open2.lpstrElementName = SOUND_KOUKA_MP3_1;

		//mciSendCommand�ł́Awave�t�@�C�����ǂݍ��݉\

		//MP3���擾
		mciSendCommand(
			0,
			MCI_OPEN, 			//�f�o�C�X���I�[�v��
			MCI_OPEN_TYPE		//MP3�t�@�C���̏ꍇ
			| MCI_OPEN_ELEMENT,	//MP3�t�@�C���̏ꍇ
			(DWORD_PTR)&open2);

		//MP3���ǂݍ��߂Ȃ������Ƃ�
		if (res_sound)
		{
			MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
		}

		//wave�̏���ݒ�
		open3.lpstrDeviceType = (LPCWSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
		open3.lpstrElementName = SOUND_KOUKA_1;

		//wave���擾
		mciSendCommand(
			0,
			MCI_OPEN,			//�f�o�C�X���I�[�v��
			MCI_OPEN_TYPE		//wave�t�@�C���̏ꍇ
			| MCI_OPEN_TYPE_ID	//wave�t�@�C���̏ꍇ
			| MCI_OPEN_ELEMENT,	//wave�t�@�C���̏ꍇ
			(DWORD_PTR)&open3);

		//wave���ǂݍ��߂Ȃ������Ƃ�
		if (res_sound)
		{
			MessageBox(hwnd, ERR_MSG_NO_READ_MP3, ERR_MSG_TITLE, MB_OK);
		}

		//�R�[���o�b�N�E�B���h�E�̃n���h��
		//�E�C���h�E�v���V�[�W���̃E�B���h�E
		//��MM_MCINOTIFY���b�Z�[�W�������L�q
		play1.dwCallback = (DWORD)hwnd; 
		play2.dwCallback = (DWORD)hwnd;
		play3.dwCallback = (DWORD)hwnd;

		//���������� WM_CREATE�ɒǉ� ����������

		////�^�C�}�[�𕪉�\(10�~���b)�ŃZ�b�g(�J�n)
		//SetTimer(
		//	hwnd,		//�֘A�t����E�B���h�E�n���h��
		//	TIMER_ID_1,	//�^�C�}�[��ID
		//	10,			//�^�C���A�E�g�l(�~���b)
		//	NULL);		//TIMERPROC�^�֐��ւ̃|�C���^/�Ȃ� ��NULL

		//				//�^�C�}�[���P�b�ŃZ�b�g(�J�n)
		//SetTimer(hwnd, TIMER_ID_2, 1000, NULL);

		//�^�C�}�[��10�~���Ԋu�ɃZ�b�g(�J�n)
		SetTimer(hwnd, TIMER_ID_FPS, 10, NULL);

		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;

	case WM_TIMER:

		//�R�����g�A�E�g
		//	switch (wp)
		//	{
		//	case TIMER_ID_1:
		//		timer_1_cnt++;
		//		break;
		//	case TIMER_ID_2:
		//		timer_2_cnt++;
		//		break;
		//	}

		switch (wp)
		{
		case TIMER_ID_FPS:

			//��ʍX�V�̎������擾����
			MY_FPS_UPDATE();

			//���L�[�������Ă��邩���肷��
			MY_CHECK_KEYDOWN();

			//�r�b�g�}�b�v���ړ�������
			MY_MOVE_BITMAP(&bmp_dragon);

			//���������� WM_TIMER�ɒǉ� ����������

			//����炷
			MY_SOUND();

			//���������� WM_TIMER�ɒǉ� ����������

			//�������[�W�����𔭐�
			//WM_PAINT���A��莞�ԂŌĂяo��
			InvalidateRect(hwnd, NULL, FALSE);

			//��ʂ��A�����ɍĕ`�悷��
			UpdateWindow(hwnd);

			//�w�肵��FPS�ɂȂ�悤�ɑ҂�
			MY_FPS_WAIT();

			break;
		}

		return 0;

	case WM_PAINT:
		//�E�B���h�E�����ĕ`�悷��Ƃ�

		//�f�o�C�X�R���e�L�X�g�̃n���h�����擾
		hdc = BeginPaint(hwnd, &ps);

		//���݂̃f�o�C�X�R���e�L�X�g��ۑ�����
		SaveDC(hdc);

		//�`��
		//MY_DRAW(hdc);

		//�t�H���g��ݒ肵�ĕ`��
		//MY_SetFontDraw(hdc);

		//����`��
		//MY_DRAW_LINE(hdc);

		//�}��`��
		//MY_DRAW_GRAPH(hdc);


		//�y�����g�p���ĕ`��
		//MY_DRAW_PEN(hdc);

		//�u���V���g�p���ĕ`��
		//MY_DRAW_BRUSH(hdc);

		//���p�`��h��Ԃ��ĕ`��
		//MY_DRAW_POLYGON(hdc);

		//�����̑��p�`��h��Ԃ��ĕ`��
		//MY_DRAW_POLYPOLYGON(hdc);

		//�Z�p�`��h��Ԃ��ĕ`�悷��
		//MY_DRAW_PENTAGON(hdc);

		//�p�b�N�}����`�悷��
		//MY_DRAW_PACMAN(hdc);

		//�����X�^�[�{�[����`�悷��
		//MY_DRAW_MONBALL(hdc);

		//�r�b�g�}�b�v��`�悷��
		MY_DRAW_BITMAP(hdc_double);

		//�}�E�X�̍��W�ʒu��`�悷��
		MY_DRAW(hdc_double);

		//���������̉摜��`��
		BitBlt(hdc, 0, 0, rect_c.right, rect_c.bottom, hdc_double, 0, 0, SRCCOPY);

		//�ۑ������f�o�C�X�R���e�L�X�𕜌�����
		RestoreDC(hdc, -1);

		//�f�o�C�X�R���e�L�X�g�̃n���h�����J������
		EndPaint(hwnd, &ps);

		return 0;

	case WM_LBUTTONDOWN:
		//�}�E�X�̍��{�^���������Ă���Ƃ�

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			//���b�Z�[�W��������
			PostMessage(
				hwnd,				//�E�B���h�E�n���h��
				WM_NCLBUTTONDOWN,	//��N���C�A���g�̈�����N���b�N����
				HTCAPTION,			//�^�C�g���o�[���N���b�N����
				MAKELPARAM(0, 0));	//�}�E�X�̍��W�F0,0

			return 0;
		}

		//�N���C�A���g�̈�O�ł��}�E�X�̓����̊Ď����J�n
		SetCapture(hwnd);

		break;

	case WM_LBUTTONUP:
		//�}�E�X�̍��{�^�����グ���Ƃ�

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			return 0;
		}

		//�N���C�A���g�̈�O�ł��}�E�X�̓����̊Ď����I��
		ReleaseCapture();

		break;

	case WM_RBUTTONDOWN:
		//�}�E�X�̉E�{�^�����������Ƃ�

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			//���b�Z�[�W�𑗂�
			SendMessage(
				hwnd,		//�E�B���h�E�n���h��
				WM_CLOSE,	//���郁�b�Z�[�W�FWM_CLOSE
				0,			//���b�Z�[�W�̏�񂻂̂P
				0);			//���b�Z�[�W�̏�񂻂̂Q

			return 0;
		}

		break;

	case WM_RBUTTONUP:
		//�}�E�X�̉E�{�^�����グ���Ƃ�

		break;

	case WM_MOUSEMOVE:
		//�}�E�X�J�[�\�����ړ������Ƃ�

		//�}�E�X�̍��W���擾
		//LPARAM lp�ɂ́A�}�E�X�̍��W�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́Ay���W�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́Ax���W�������Ă���

		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		pt_Mouse.x = LOWORD(lp);
		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		pt_Mouse.y = HIWORD(lp);

		//�N���C�A���g�̈�O�̑Ώ�
		if (pt_Mouse.x < window_Size.left)
			pt_Mouse.x = window_Size.left;

		if (pt_Mouse.x >= window_Size.right)
			pt_Mouse.x = window_Size.right - 1;

		if (pt_Mouse.y < window_Size.top)
			pt_Mouse.y = window_Size.top;

		if (pt_Mouse.y >= window_Size.bottom)
			pt_Mouse.y = window_Size.bottom - 1;

		break;
	case WM_SIZE:
		//��ʂ̃T�C�Y���ς�����Ƃ�

		//�E�B���h�E�̃T�C�Y���擾
		//LPARAM lp�ɂ́A�E�C���h�E�̃T�C�Y�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́A�����̃T�C�Y�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́A���̃T�C�Y�������Ă���

		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		window_Size.bottom = HIWORD(lp);
		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		window_Size.right = LOWORD(lp);

		//��ʂ��ǂ̂悤�ɕω����������f
		switch (wp)
		{
		case SIZE_RESTORED:
			//�E�B���h�E�T�C�Y���ς�����Ƃ�

			break;
		case SIZE_MINIMIZED:
			//�E�B���h�E���ŏ������ꂽ�Ƃ�

			break;

		case SIZE_MAXIMIZED:
			//�E�B���h�E���ő剻���ꂽ�Ƃ�

			break;
		}

		//��ʂ��ύX���ꂽ��AWM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ��邽��
		//�ĕ`��̏����͕s�v�ł���

		break;

	case WM_KEYDOWN:
		//�L�[�{�[�h�ŃL�[���������Ƃ�

		//�R�����g�A�E�g
		//TCHAR Str_KeyValue[128];
		//wsprintf(Str_KeyValue, TEXT("�L�[�R�[�h�F%0X"),wp);
		//MessageBox(hwnd, Str_KeyValue, TEXT("KeyDown"), MB_OK);

		//���z�L�[�R�[�h�𐮌`����
		MY_FORMAT_KEYCODE(wp, msg);

		return 0;

	case WM_KEYUP:
		//�L�[�{�[�h�ŃL�[���������Ƃ�

		//���z�L�[�R�[�h�𐮌`����
		MY_FORMAT_KEYCODE(wp, msg);

		//���z�L�[�R�[�h�𕶎��Ƃ��Đ��`����
		MY_FORMAT_KEYCHAR(wp, msg);

		return 0;

	case WM_CHAR:
		//���z�L�[�R�[�h�𕶎��ɕϊ������Ƃ�
		//WM_KEYDOWN�̂��ƂɁA���̃��b�Z�[�W�����s�����

		//���z�L�[�R�[�h�𕶎��Ƃ��Đ��`����
		MY_FORMAT_KEYCHAR(wp, msg);

		return 0;

	case WM_SYSKEYDOWN:
		//�V�X�e�����̃L�[(Alt�L�[)���������Ƃ�

		//���z�L�[�R�[�h�𐮌`����
		MY_FORMAT_KEYCODE(wp, msg);

		return 0;

	case WM_SYSKEYUP:
		//�V�X�e�����̃L�[(Alt�L�[)���グ���Ƃ�

		//���z�L�[�R�[�h�𐮌`����
		MY_FORMAT_KEYCODE(wp, msg);

		//���z�L�[�R�[�h�𕶎��Ƃ��Đ��`����
		MY_FORMAT_KEYCHAR(wp, msg);

		return 0;

	case  WM_SYSCHAR:

		//���z�V�X�e���L�[�R�[�h�𕶎��ɕϊ������Ƃ�
		//WM_SYSKEYDOWN�̂��ƂɁA���̃��b�Z�[�W�����s�����

		//���z�L�[�R�[�h�𕶎��Ƃ��Đ��`����
		MY_FORMAT_KEYCHAR(wp, msg);

		return 0;

		//���������� ���b�Z�[�W��ǉ� ����������

	case MM_MCINOTIFY:
		//MP3���Đ�

		if (lp == open1.wDeviceID)
		{
			//�Đ����I�������Ƃ�
			if (wp == MCI_NOTIFY_SUCCESSFUL)
			{
				//�V�[�N�o�[��擪�ɖ߂�
				mciSendCommand(
					open1.wDeviceID,
					MCI_SEEK,
					MCI_SEEK_TO_START,
					0);
			}
			return 0;
		}
		else if (lp == open2.wDeviceID)
		{
			//�Đ����I�������Ƃ�
			if (wp == MCI_NOTIFY_SUCCESSFUL)
			{
				//�V�[�N�o�[��擪�ɖ߂�
				mciSendCommand(
					open2.wDeviceID,
					MCI_SEEK,
					MCI_SEEK_TO_START,
					0);
			}
			return 0;
		}
		else if (lp == open3.wDeviceID)
		{
			//�Đ����I�������Ƃ�
			if (wp == MCI_NOTIFY_SUCCESSFUL)
			{
				//�V�[�N�o�[��擪�ɖ߂�
				mciSendCommand(
					open3.wDeviceID,
					MCI_SEEK,
					MCI_SEEK_TO_START,
					0);
			}
			return 0;
		}

		break;

		//���������� ���b�Z�[�W��ǉ� ����������

	case WM_CLOSE:
		//����{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�E�B���h�E���I�������܂�"),
			TEXT("CLOSE"),
			MB_OK);

		break;

	case WM_DESTROY:
		//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		//�ꎞ�I�ɓǂݍ��� judge hard�t�H���g���폜
		RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

		//�ꎞ�I�ɓǂݍ��� ���ʂ������}�W�b�N�t�H���g���폜
		RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

		//�r�b�g�}�b�v�n���h�����폜
		DeleteObject(bmp_dragon.hbmp);

		//�������f�o�C�X�R���e�L�X�g��j��
		DeleteDC(bmp_dragon.mhdc);

		//�r�b�g�}�b�v�n���h�����폜
		DeleteObject(bmp_dragon_white.hbmp);

		//�������f�o�C�X�R���e�L�X�g��j��
		DeleteDC(bmp_dragon_white.mhdc);

		//�r�b�g�}�b�v�n���h�����폜
		DeleteObject(bmp_dragon_mask.hbmp);

		//�������f�o�C�X�R���e�L�X�g��j��
		DeleteDC(bmp_dragon_mask.mhdc);

		//�r�b�g�}�b�v�n���h�����폜
		DeleteObject(hbmp_double);

		//�������f�o�C�X�R���e�L�X�g��j��
		DeleteDC(hdc_double);

		//���������� WM_DESTROY�ɒǉ� ����������

		//MP3�t�@�C�������
		mciSendCommand(open1.wDeviceID, MCI_CLOSE, 0, 0);
		mciSendCommand(open2.wDeviceID, MCI_CLOSE, 0, 0);

		//wave�t�@�C�������
		mciSendCommand(open3.wDeviceID, MCI_CLOSE, 0, 0);

		//���������� WM_DESTROY�ɒǉ� ����������

		////�^�C�}�[�P���폜(�I��)
		//KillTimer(hwnd, TIMER_ID_2);

		////�^�C�}�[�Q���폜(�I��)
		//KillTimer(hwnd, TIMER_ID_1);

		//FPS�^�C�}�[���폜(�I��)
		KillTimer(hwnd, TIMER_ID_FPS);

		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		PostQuitMessage(0);
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}