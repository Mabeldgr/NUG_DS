#pragma once   //_____________________________________________ InfoClienteDlg.h  
#include "resource.h"

class InfoClienteDlg: public Win::Dialog
{
public:
	InfoClienteDlg()
	{
		userx_id = -1;
	}
	~InfoClienteDlg()
	{
	}
	int userx_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Label lb2;
	Win::Label lb3;
	Win::Label lb4;
	Win::Textbox tbxNombre;
	Win::Textbox tbxDomicilio;
	Win::Textbox tbxTelefono;
	Win::Textbox tbxEdad;
	Win::Label lb5;
	Win::Label lb6;
	Win::Label lb7;
	Win::Label lb8;
	Win::Label lb9;
	Win::Textbox tbxPeso;
	Win::Textbox tbxAltura;
	Win::Textbox tbxCadera;
	Win::Textbox tbxCintura;
	Win::Textbox tbxIMC;
	Win::Label lb10;
	Win::Textbox tbxAntef;
	Win::Label lb11;
	Win::Textbox tbxActivf;
	Win::Label lb12;
	Win::Textbox tbxTiempo;
	Win::Label lb13;
	Win::Textbox tbxActivfrec;
	Win::Label lb14;
	Win::Textbox tbxPadact;
	Win::Label lb15;
	Win::Textbox tbxCirugias;
	Win::Label lb16;
	Win::Label lb17;
	Win::Label lb18;
	Win::Label lb19;
	Win::Label lb20;
	Win::Textbox tbxComd;
	Win::Textbox tbxColacd;
	Win::Textbox tbxConsuag;
	Win::Textbox tbxHorafg;
	Win::Textbox tbxSaltacomd;
	Win::Button btGuardar;
	Win::Button btCancelar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(27.22562);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(17.54188);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Nombre: ", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.42333, 0.34396, 1.87854, 0.60854, hWnd, 1000);
		lb2.CreateX(NULL, L"Domicilio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.42333, 1.29646, 1.87854, 0.60854, hWnd, 1001);
		lb3.CreateX(NULL, L"Telefono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.42333, 2.24896, 1.87854, 0.60854, hWnd, 1002);
		lb4.CreateX(NULL, L"Edad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.42333, 3.01625, 1.87854, 0.60854, hWnd, 1003);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.59292, 0.34396, 10.98021, 0.60854, hWnd, 1004);
		tbxDomicilio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.59292, 1.29646, 10.98021, 0.60854, hWnd, 1005);
		tbxTelefono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.59292, 2.24896, 10.98021, 0.60854, hWnd, 1006);
		tbxEdad.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.59292, 3.09563, 1.77271, 0.60854, hWnd, 1007);
		lb5.CreateX(NULL, L"Peso", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.26104, 0.37042, 1.40229, 0.60854, hWnd, 1008);
		lb6.CreateX(NULL, L"Altura", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.26104, 1.37583, 1.40229, 0.60854, hWnd, 1009);
		lb7.CreateX(NULL, L"Cadera", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 18.67958, 0.31750, 1.45521, 0.60854, hWnd, 1010);
		lb8.CreateX(NULL, L"Cintura", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 18.67958, 1.53458, 1.45521, 0.60854, hWnd, 1011);
		lb9.CreateX(NULL, L"IMC", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 23.12458, 0.84667, 2.01083, 0.60854, hWnd, 1012);
		tbxPeso.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 15.82208, 0.34396, 1.90500, 0.60854, hWnd, 1013);
		tbxAltura.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 15.82208, 1.40229, 1.90500, 0.60854, hWnd, 1014);
		tbxCadera.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 20.42583, 0.29104, 2.14312, 0.60854, hWnd, 1015);
		tbxCintura.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 20.42583, 1.58750, 2.14312, 0.60854, hWnd, 1016);
		tbxIMC.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 25.21479, 0.82021, 1.82562, 0.60854, hWnd, 1017);
		lb10.CreateX(NULL, L"Antecedentes familiare", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.37042, 3.91583, 4.60375, 0.60854, hWnd, 1018);
		tbxAntef.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 5.29167, 3.78354, 7.96396, 2.88396, hWnd, 1019);
		lb11.CreateX(NULL, L"Actividades fisicas que realiza", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 6.93208, 4.78896, 0.60854, hWnd, 1020);
		tbxActivf.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 5.26521, 6.90563, 7.96396, 2.88396, hWnd, 1021);
		lb12.CreateX(NULL, L"Tiempo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.47625, 10.23938, 1.95792, 0.60854, hWnd, 1022);
		tbxTiempo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.64583, 10.23938, 2.43417, 0.60854, hWnd, 1023);
		lb13.CreateX(NULL, L"Frecuencia", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 5.58271, 10.23938, 2.27542, 0.60854, hWnd, 1024);
		tbxActivfrec.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 8.14917, 10.23938, 4.57729, 0.60854, hWnd, 1025);
		lb14.CreateX(NULL, L"Padecimientos actuales", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.29104, 11.32417, 3.96875, 0.60854, hWnd, 1026);
		tbxPadact.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 5.18583, 11.37708, 8.12271, 2.77812, hWnd, 1027);
		lb15.CreateX(NULL, L"Cirugias", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.29104, 14.60500, 3.96875, 0.60854, hWnd, 1028);
		tbxCirugias.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 5.18583, 14.57854, 8.12271, 2.77812, hWnd, 1029);
		lb16.CreateX(NULL, L"Comidas al dia", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.34042, 3.51896, 4.73604, 0.60854, hWnd, 1030);
		lb17.CreateX(NULL, L"Colaciones al dia", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.34042, 4.57729, 4.73604, 0.60854, hWnd, 1031);
		lb18.CreateX(NULL, L"Consumo de agua al dia", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.34042, 5.60917, 4.73604, 0.60854, hWnd, 1032);
		lb19.CreateX(NULL, L"Tiene horarios fijos de comida", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.34042, 6.64104, 4.73604, 0.60854, hWnd, 1033);
		lb20.CreateX(NULL, L"Acostumbra saltar comidas", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.34042, 7.46125, 4.73604, 0.60854, hWnd, 1034);
		tbxComd.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.39396, 3.49250, 6.87917, 0.60854, hWnd, 1035);
		tbxColacd.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.39396, 4.49792, 6.87917, 0.60854, hWnd, 1036);
		tbxConsuag.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.39396, 5.63563, 6.87917, 0.60854, hWnd, 1037);
		tbxHorafg.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.39396, 6.66750, 6.87917, 0.60854, hWnd, 1038);
		tbxSaltacomd.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.39396, 7.51417, 6.87917, 0.60854, hWnd, 1039);
		btGuardar.CreateX(NULL, L"Guardar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 16.82750, 9.60437, 3.06917, 1.64042, hWnd, 1040);
		btCancelar.CreateX(NULL, L"Cancelar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 21.14021, 9.60437, 3.06917, 1.64042, hWnd, 1041);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		lb2.Font = fontArial009A;
		lb3.Font = fontArial009A;
		lb4.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		tbxDomicilio.Font = fontArial009A;
		tbxTelefono.Font = fontArial009A;
		tbxEdad.Font = fontArial009A;
		lb5.Font = fontArial009A;
		lb6.Font = fontArial009A;
		lb7.Font = fontArial009A;
		lb8.Font = fontArial009A;
		lb9.Font = fontArial009A;
		tbxPeso.Font = fontArial009A;
		tbxAltura.Font = fontArial009A;
		tbxCadera.Font = fontArial009A;
		tbxCintura.Font = fontArial009A;
		tbxIMC.Font = fontArial009A;
		lb10.Font = fontArial009A;
		tbxAntef.Font = fontArial009A;
		lb11.Font = fontArial009A;
		tbxActivf.Font = fontArial009A;
		lb12.Font = fontArial009A;
		tbxTiempo.Font = fontArial009A;
		lb13.Font = fontArial009A;
		tbxActivfrec.Font = fontArial009A;
		lb14.Font = fontArial009A;
		tbxPadact.Font = fontArial009A;
		lb15.Font = fontArial009A;
		tbxCirugias.Font = fontArial009A;
		lb16.Font = fontArial009A;
		lb17.Font = fontArial009A;
		lb18.Font = fontArial009A;
		lb19.Font = fontArial009A;
		lb20.Font = fontArial009A;
		tbxComd.Font = fontArial009A;
		tbxColacd.Font = fontArial009A;
		tbxConsuag.Font = fontArial009A;
		tbxHorafg.Font = fontArial009A;
		tbxSaltacomd.Font = fontArial009A;
		btGuardar.Font = fontArial009A;
		btCancelar.Font = fontArial009A;
	}
	//_________________________________________________
	void btGuardar_Click(Win::Event& e);
	void btCancelar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btGuardar.IsEvent(e, BN_CLICKED)) {btGuardar_Click(e); return true;}
		if (btCancelar.IsEvent(e, BN_CLICKED)) {btCancelar_Click(e); return true;}
		return false;
	}
};
