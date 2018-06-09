#pragma once   //_____________________________________________ CitaDlg.h  
#include "resource.h"

class CitaDlg: public Win::Dialog
{
public:
	CitaDlg()
	{
	}
	~CitaDlg()
	{
	}
	int cita_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxDieta;
	Win::Label lb2;
	Win::Textbox tbxFecha;
	Win::Textbox tbxObjetivos;
	Win::Label lb3;
	Win::Button btAceptar;
	Win::Button btCancelar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.43000);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.16542);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Dieta a seguir", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.15875, 0.34396, 2.96333, 0.60854, hWnd, 1000);
		tbxDieta.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 0.52917, 1.45521, 10.55687, 4.63021, hWnd, 1001);
		lb2.CreateX(NULL, L"Fecha", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.34396, 6.53521, 2.59292, 0.60854, hWnd, 1002);
		tbxFecha.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.30729, 6.56167, 5.47687, 0.60854, hWnd, 1003);
		tbxObjetivos.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 3.30729, 7.62000, 7.93750, 1.85208, hWnd, 1004);
		lb3.CreateX(NULL, L"Objetivo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.34396, 7.67292, 2.59292, 0.60854, hWnd, 1005);
		btAceptar.CreateX(NULL, L"Aceptar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.77271, 9.57792, 2.75167, 1.40229, hWnd, 1006);
		btCancelar.CreateX(NULL, L"Cancelar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 7.38187, 9.57792, 2.75167, 1.40229, hWnd, 1007);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		tbxDieta.Font = fontArial009A;
		lb2.Font = fontArial009A;
		tbxFecha.Font = fontArial009A;
		tbxObjetivos.Font = fontArial009A;
		lb3.Font = fontArial009A;
		btAceptar.Font = fontArial009A;
		btCancelar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAceptar_Click(Win::Event& e);
	void btCancelar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAceptar.IsEvent(e, BN_CLICKED)) {btAceptar_Click(e); return true;}
		if (btCancelar.IsEvent(e, BN_CLICKED)) {btCancelar_Click(e); return true;}
		return false;
	}
};
