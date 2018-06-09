#pragma once   //_____________________________________________ PerfilDlg.h  
#include "resource.h"

class PerfilDlg: public Win::Dialog
{
public:
	PerfilDlg()
	{
	}
	~PerfilDlg()
	{
	}
	int userx_id;
	void UpDateListViewCitas();
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Label lb2;
	Win::Label lb3;
	Win::Label lb4;
	Win::Textbox tbxNombre;
	Win::Textbox tbxPeso;
	Win::Textbox tbxAltura;
	Win::Textbox tbxCintura;
	Win::Label lb5;
	Win::Textbox tbxIMC;
	Win::Label lb6;
	Win::Textbox tbxCadera;
	Win::ListView lvCitas;
	Win::Button btAgregarCita;
	Win::Button btVerCita;
	Win::Button btRegresar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(14.73729);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.98021);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.63500, 0.92604, 2.30187, 0.60854, hWnd, 1000);
		lb2.CreateX(NULL, L"Peso", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.63500, 1.82562, 2.30187, 0.60854, hWnd, 1001);
		lb3.CreateX(NULL, L"Altura", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.63500, 2.80458, 2.30187, 0.60854, hWnd, 1002);
		lb4.CreateX(NULL, L"Cintura", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.63500, 3.78354, 2.30187, 0.60854, hWnd, 1003);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 3.25438, 0.92604, 8.81062, 0.60854, hWnd, 1004);
		tbxPeso.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 3.25438, 1.85208, 5.84729, 0.60854, hWnd, 1005);
		tbxAltura.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 3.25438, 2.91042, 5.84729, 0.60854, hWnd, 1006);
		tbxCintura.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 3.25438, 3.86292, 5.84729, 0.60854, hWnd, 1007);
		lb5.CreateX(NULL, L"IMC", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9.49854, 1.93146, 2.56646, 0.60854, hWnd, 1008);
		tbxIMC.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 9.47208, 2.91042, 2.56646, 0.60854, hWnd, 1009);
		lb6.CreateX(NULL, L"Cadera", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9.44562, 3.96875, 2.19604, 0.60854, hWnd, 1010);
		tbxCadera.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 11.72104, 3.94229, 2.61938, 0.60854, hWnd, 1011);
		lvCitas.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.76729, 5.18583, 13.78479, 4.55083, hWnd, 1012);
		btAgregarCita.CreateX(NULL, L"Agregar Cita", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.13771, 10.10708, 3.43958, 0.68792, hWnd, 1013);
		btVerCita.CreateX(NULL, L"Ver Cita", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 5.68854, 10.10708, 3.43958, 0.68792, hWnd, 1014);
		btRegresar.CreateX(NULL, L"Regresar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 10.90083, 10.10708, 3.43958, 0.68792, hWnd, 1015);
		lvCitas.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		lb2.Font = fontArial009A;
		lb3.Font = fontArial009A;
		lb4.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		tbxPeso.Font = fontArial009A;
		tbxAltura.Font = fontArial009A;
		tbxCintura.Font = fontArial009A;
		lb5.Font = fontArial009A;
		tbxIMC.Font = fontArial009A;
		lb6.Font = fontArial009A;
		tbxCadera.Font = fontArial009A;
		lvCitas.Font = fontArial009A;
		btAgregarCita.Font = fontArial009A;
		btVerCita.Font = fontArial009A;
		btRegresar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregarCita_Click(Win::Event& e);
	void btVerCita_Click(Win::Event& e);
	void btRegresar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregarCita.IsEvent(e, BN_CLICKED)) {btAgregarCita_Click(e); return true;}
		if (btVerCita.IsEvent(e, BN_CLICKED)) {btVerCita_Click(e); return true;}
		if (btRegresar.IsEvent(e, BN_CLICKED)) {btRegresar_Click(e); return true;}
		return false;
	}
};
