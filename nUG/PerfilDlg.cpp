#include "stdafx.h"  //_____________________________________________ PerfilDlg.cpp
#include "PerfilDlg.h"
#include "CitaDlg.h"
#include "nUG.h"
#include "InfoClienteDlg.h"

void PerfilDlg::Window_Open(Win::Event& e)
{
	this->Text = L"Perfil";

	UpDateListViewCitas();
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if ( userx_id < 0) return;
		//Sys::Format(cmd, L"SELECT nombre,peso, altura, cintura, cadera, imc  FROM clienteinfo  WHERE userx_id=%d",userx_id );
		Sys::Format(cmd, L"select c.nombre as nombre, c.peso as peso, c.altura as altura, c.cadera as cadera, c.cintura as cintura, c.imc as imc from clienteinfo c, cita ci where c.userx_id = ci.userx_id", userx_id);
		conn.ExecuteSelect(cmd);
		tbxNombre.MaxTextLength = 150;
		conn.BindColumn(1, tbxNombre, 128);
		tbxPeso.MaxTextLength = 150;
		conn.BindColumn(2, tbxPeso, 128);
		tbxAltura.MaxTextLength = 150;
		conn.BindColumn(3, tbxAltura, 128);
		tbxCadera.MaxTextLength = 150;
		conn.BindColumn(4, tbxCadera, 128);
		tbxCintura.MaxTextLength = 150;
		conn.BindColumn(5, tbxCintura, 128);
		tbxIMC.MaxTextLength = 150;
		conn.BindColumn(6, tbxIMC, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"Ningun dato es regresado", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	////________________________________________________________ lvCitas
	//lvCitas.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	//lvCitas.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	//lvCitas.Items.Add(0, L"Monday");
	//lvCitas.Items[0][1].Text = L"Math Class";
}

void PerfilDlg::UpDateListViewCitas()
{
	Win::HourGlassCursor hgc(true);

	lvCitas.SetRedraw(false);
	lvCitas.Items.DeleteAll();
	lvCitas.DeleteAllColumns();

	Sql::SqlConnection conn;
	try
	{

		conn.OpenSession(hWnd, CONNECTION_STRING);
		lvCitas.Cols.Add(0, LVCFMT_LEFT, 100, L"Fecha");
		//conn.ExecuteSelect(L"select c.fecha as fecha from cita c", 100, lvCitas);
		conn.ExecuteSelect(L"select ci.fecha as fecha from clienteinfo c, cita ci where c.userx_id = ci.userx_id", 100, lvCitas);
	}
	catch (Sql::SqlException ex)
	{

		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);

	}
	lvCitas.SetRedraw(true);
}

void PerfilDlg::btAgregarCita_Click(Win::Event& e)
{
	CitaDlg dlg;
	dlg.BeginDialog(hWnd);
}

void PerfilDlg::btVerCita_Click(Win::Event& e)
{
	LPARAM cita_id;
	if (lvCitas.GetSelectedData(cita_id) == false)return;
	CitaDlg dlg;
	dlg.cita_id = cita_id;
	dlg.BeginDialog(hWnd);

}

void PerfilDlg::btRegresar_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
	
	
}

