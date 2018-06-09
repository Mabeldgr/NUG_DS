#pragma once  //______________________________________ nUG.h  
#include "Resource.h"
class nUG: public Win::Dialog
{
public:
	nUG()
	{
	}
	~nUG()
	{
	}
	CG::DDBitmap bitmap;
	int userx_id = 0;
	int cita_id = 0;
	void UpDateListView();
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvClientes;
	Win::Button btNuevo;
	Win::Button btEdit;
	Win::Button btEliminar;
	Win::Button btAbrir;
	Win::Label pic1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(12.96458);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.21833);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"nUG";
		lvClientes.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 1.03188, 3.25438, 11.74750, 5.50333, hWnd, 1000);
		btNuevo.CreateX(NULL, L"Nuevo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.08479, 9.52500, 1.71979, 1.50812, hWnd, 1001);
		btEdit.CreateX(NULL, L"Edit", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.57187, 9.49854, 1.93146, 1.50812, hWnd, 1002);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.27062, 9.47208, 2.19604, 1.53458, hWnd, 1003);
		btAbrir.CreateX(NULL, L"Abrir", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 9.12813, 9.52500, 2.16958, 1.48167, hWnd, 1004);
		pic1.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, 2.85750, 0.05292, 6.64104, 3.12208, hWnd, 1005);
		lvClientes.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvClientes.Font = fontArial009A;
		btNuevo.Font = fontArial009A;
		btEdit.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btAbrir.Font = fontArial009A;
	}
	//_________________________________________________
	void btNuevo_Click(Win::Event& e);
	void btEdit_Click(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void btAbrir_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btNuevo.IsEvent(e, BN_CLICKED)) {btNuevo_Click(e); return true;}
		if (btEdit.IsEvent(e, BN_CLICKED)) {btEdit_Click(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btAbrir.IsEvent(e, BN_CLICKED)) {btAbrir_Click(e); return true;}
		return false;
	}
};
