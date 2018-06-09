#include "stdafx.h"  //_____________________________________________ CitaDlg.cpp
#include "CitaDlg.h"
#include "InfoClienteDlg.h"
#include "nUG.h"
#include "PerfilDlg.h"

void CitaDlg::Window_Open(Win::Event& e)
{
	this->Text = L"Cita";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (cita_id < 0)return;
		Sys::Format(cmd, L"SELECT c.dieta, c.fecha, c.objetivos FROM cita c, clienteinfo ci WHERE c.userx_id = ci.userx_id", cita_id);
		conn.ExecuteSelect(cmd);
		tbxDieta.MaxTextLength = 600;
		conn.BindColumn(1, tbxDieta, 600);
		tbxFecha.MaxTextLength = 50;
		conn.BindColumn(2, tbxFecha, 128);
		tbxObjetivos.MaxTextLength = 100;
		conn.BindColumn(3, tbxObjetivos, 128);
		if (conn.Fetch() == false) {
			this->MessageBox(L"Ningun dato es regresado", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}



void CitaDlg::btAceptar_Click(Win::Event& e)
{
	tr1::wregex regextbxDieta(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxDieta.Text, regextbxDieta) == false)
	{
		tbxDieta.ShowBalloonTip(L"Dieta", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxFecha(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxFecha.Text, regextbxFecha) == false)
	{
		tbxFecha.ShowBalloonTip(L"Fecha", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxObjetivos(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxObjetivos.Text, regextbxObjetivos) == false)
	{
		tbxObjetivos.ShowBalloonTip(L"Objetivos", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"cita", L"cita_id", cita_id);
	sb.Bind(L"dieta", tbxDieta);
	sb.Bind(L"fecha", tbxFecha);
	sb.Bind(L"objetivos", tbxObjetivos);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows != 1) {
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: numero de filas afectado", MB_OK | MB_ICONERROR);
			return;
		}

	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
}

void CitaDlg::btCancelar_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

