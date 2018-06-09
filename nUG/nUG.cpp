#include "stdafx.h"  //________________________________________ nUG.cpp
#include "nUG.h"
#include "InfoClienteDlg.h"
#include "PerfilDlg.h"
#include "CitaDlg.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	nUG app;
	return app.BeginDialog(IDI_nUG, hInstance);
}

void nUG::Window_Open(Win::Event& e)
{
	this->Text = L"NUG ";
	//Sql::SqlConnection conn1;
	//try
	//{
	//	conn1.OpenSession(hWnd, CONNECTION_STRING);
	//	conn1.ExecuteSelect(L"SELECT userx_id, name FROM clienteinfo", 100, lvClientes);//dd?

	//}
	//catch (Sql::SqlException e)
	//{
	//	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	//}
	//lvClientes.SelectedIndex = 0;

	//wstring cmd;
	//Sys::Format(cmd, L"SELECT name FROM clienteinfo WHERE userx_id= %d", userx_id);
	//

	//Sql::SqlConnection conn;
	//try
	//{
	//	int estate;
	//	conn.OpenSession(hWnd, CONNECTION_STRING);
	//	estate = conn.GetInt()
	//}
	//________________________________________________________ lvClientes
	//lvClientes.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	//lvClientes.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	//lvClientes.Items.Add(0, L"Monday");
	//lvClientes.Items[0][1].Text = L"Math Class";
	UpDateListView();
	//________________________________________________________ pic1
	
	bitmap.CreateFromResource(this->hInstance, IDB_LOGO);
	pic1.SetImage(bitmap);
}

void nUG::UpDateListView() {
	Win::HourGlassCursor hgc(true);

	lvClientes.SetRedraw(false);
	lvClientes.Items.DeleteAll();
	lvClientes.DeleteAllColumns();

	Sql::SqlConnection conn;
	try
	{

		conn.OpenSession(hWnd, CONNECTION_STRING);
		lvClientes.Cols.Add(0, LVCFMT_LEFT, 100, L"Nombre");
		conn.ExecuteSelect(L"select nombre  from clienteinfo", 100, lvClientes);
	}
	catch(Sql::SqlException ex)
	{
		
		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);

	}
	lvClientes.SetRedraw(true);
}
void nUG::btNuevo_Click(Win::Event& e)
{
	InfoClienteDlg dlg;
	dlg.BeginDialog(hWnd);
	UpDateListView();

}

void nUG::btEdit_Click(Win::Event& e)
{
	LPARAM userx_id;
	if (lvClientes.GetSelectedData(userx_id) == false)return;
	InfoClienteDlg dlg;
	dlg.userx_id = userx_id;
	dlg.BeginDialog(hWnd);
	UpDateListView();
}

void nUG::btEliminar_Click(Win::Event& e)
{
	const int selectedCount = lvClientes.GetSelectedCount();
	if (selectedCount < 0)return;

	Win::HourGlassCursor hgc(true);
	Sql::SqlConnection conn;
	wstring cmd;
	int userx_id, cita_id;
	int row = 0;
	int index = -1;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		for (int i = 0; i < selectedCount; i++) {
			if (this->MessageBox(L"¿Deseas borrar este perfil?", L"Borrar Cliente", MB_YESNO | MB_ICONQUESTION)!= IDYES)return;
			index = lvClientes.GetNextSelectedIndex(index);
			if (index < 0) break;

			userx_id = lvClientes.Items[index].Data;
			Sys::Format(cmd, L"DELETE c.nombre as name from clienteinfo c, cita ci where c.userx_id = ci.userx_id = %id ", userx_id);
		}
		

	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	UpDateListView();
}

void nUG::btAbrir_Click(Win::Event& e)
{
	PerfilDlg dlg;
	dlg.BeginDialog(hWnd);
}

