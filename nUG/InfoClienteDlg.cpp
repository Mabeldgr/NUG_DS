#include "stdafx.h"  //_____________________________________________ InfoClienteDlg.cpp
#include "InfoClienteDlg.h"
#include "PerfilDlg.h"
#include "CitaDlg.h"
#include "nUG.h"

void InfoClienteDlg::Window_Open(Win::Event& e)
{
	this->Text = L"Informacion de Cliente";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (userx_id < 0) return;
		Sys::Format(cmd, L"select c.nombre as nombre, c.domicilio as domicilio, c.telefono as telefono, c.edad as edad, c.antecedentes as antecedentes, c.actividades as actividades, c.tiempo as tiempo, c.frecuencia as frecuencia, c.padecimientos_act as padecimientos_act, c.cirugias as cirugias, c.peso as peso, c.altura as altura, c.cadera as cadera, c.cintura as cintura, c.imc as imc, c.comidas_aldia as comidas_aldia, c.colaciones_aldia as colaciones_aldia, c.consum_agua as consum_agua, c.horarios_fijos as horarios_fijos, c.salta_comidas as salta_comidas from clienteinfo c, cita ci where c.userx_id = ci.userx_id", userx_id);
		conn.ExecuteSelect(cmd);
		tbxNombre.MaxTextLength = 45;
		conn.BindColumn(1, tbxNombre, 128);
		tbxDomicilio.MaxTextLength = 35;
		conn.BindColumn(2, tbxDomicilio, 128);
		tbxTelefono.MaxTextLength = 25;
		conn.BindColumn(3, tbxTelefono, 128);
		tbxEdad.MaxTextLength = 10;
		conn.BindColumn(4, tbxEdad, 128);
		tbxAntef.MaxTextLength = 400;
		conn.BindColumn(5,tbxAntef, 128);
		tbxActivf.MaxTextLength = 300;
		conn.BindColumn(6, tbxActivf, 128);
		tbxTiempo.MaxTextLength = 15;
		conn.BindColumn(7, tbxTiempo, 128);
		tbxActivfrec.MaxTextLength = 400;
		conn.BindColumn(8, tbxActivfrec, 128);
		tbxPadact.MaxTextLength = 400;
		conn.BindColumn(9, tbxPadact, 128);
		tbxCirugias.MaxTextLength = 400;
		conn.BindColumn(10, tbxCirugias, 128);
		tbxPeso.MaxTextLength = 35;
		conn.BindColumn(11, tbxPeso, 128);
		tbxAltura.MaxTextLength = 35;
		conn.BindColumn(12, tbxAltura, 128);
		tbxCadera.MaxTextLength = 35;
		conn.BindColumn(13, tbxCadera, 128);
		tbxCintura.MaxTextLength = 35;
		conn.BindColumn(14, tbxCintura, 128);
		tbxIMC.MaxTextLength = 10;
		conn.BindColumn(15, tbxIMC, 128);
		tbxComd.MaxTextLength = 15;
		conn.BindColumn(16, tbxComd, 128);
		tbxColacd.MaxTextLength = 15;
		conn.BindColumn(17, tbxColacd, 128);
		tbxConsuag.MaxTextLength = 15;
		conn.BindColumn(18, tbxConsuag, 128);
		tbxHorafg.MaxTextLength = 20;
		conn.BindColumn(19, tbxHorafg, 128);
		tbxSaltacomd.MaxTextLength = 20;
		conn.BindColumn(20, tbxSaltacomd, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"Ningun dato es regresado", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

}



void InfoClienteDlg::btGuardar_Click(Win::Event& e)
{
	tr1::wregex regextbxNombre(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxNombre.Text, regextbxNombre) == false)
	{
		tbxNombre.ShowBalloonTip(L"Nombre", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxDomicilio(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxDomicilio.Text, regextbxDomicilio) == false)
	{
		tbxDomicilio.ShowBalloonTip(L"Domicilio", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxTelefono(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxTelefono.Text, regextbxTelefono) == false)
	{
		tbxTelefono.ShowBalloonTip(L"Telefono", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxEdad(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxEdad.Text, regextbxEdad) == false)
	{
		tbxEdad.ShowBalloonTip(L"Edad", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxAntef(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxAntef.Text, regextbxAntef) == false)
	{
		tbxAntef.ShowBalloonTip(L"Antecedente fisicos", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxActivf(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxActivf.Text, regextbxActivf) == false)
	{
		tbxActivf.ShowBalloonTip(L"Actividades fisicas", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxTiempo(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxTiempo.Text, regextbxTiempo) == false)
	{
		tbxTiempo.ShowBalloonTip(L"Tiempo", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxActivfrec(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxActivfrec.Text, regextbxActivf) == false)
	{
		tbxActivfrec.ShowBalloonTip(L"Frecuencia de las actividades", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxPadact(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxPadact.Text, regextbxPadact) == false)
	{
		tbxPadact.ShowBalloonTip(L"Padecimientos actuales", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxCirugias(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxCirugias.Text, regextbxCirugias) == false)
	{
		tbxCirugias.ShowBalloonTip(L"Cirugias", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxPeso(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxPeso.Text, regextbxPeso) == false)
	{
		tbxPeso.ShowBalloonTip(L"Peso", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxAltura(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxAltura.Text, regextbxAltura) == false)
	{
		tbxAltura.ShowBalloonTip(L"Altura", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxCadera(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxCadera.Text, regextbxCadera) == false)
	{
		tbxCadera.ShowBalloonTip(L"Cadera", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxCintura(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxCintura.Text, regextbxCintura) == false)
	{
		tbxCintura.ShowBalloonTip(L"Cintura", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxIMC(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxIMC.Text, regextbxIMC) == false)
	{
		tbxIMC.ShowBalloonTip(L"Indice de Masa Corporal", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxComd(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxComd.Text, regextbxComd) == false)
	{
		tbxComd.ShowBalloonTip(L"Comidas al dia", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxColacd(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxColacd.Text, regextbxColacd) == false)
	{
		tbxColacd.ShowBalloonTip(L"Colaciones al día", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxConsuag(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxConsuag.Text, regextbxConsuag) == false)
	{
		tbxConsuag.ShowBalloonTip(L"Consume agua", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxHorafg(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxHorafg.Text, regextbxHorafg) == false)
	{
		tbxNombre.ShowBalloonTip(L"Horarios fijos de comida", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxSaltacomd(L"[A-Za-z0-9-\\s]+");
	if (tr1::regex_match(tbxSaltacomd.Text, regextbxSaltacomd) == false)
	{
		tbxSaltacomd.ShowBalloonTip(L"Salta comidas del día", L"Por favor de uno o mas caracteres", TTI_ERROR);
		return;
	}
	Sql::StringBuilder 	sb(L"clienteinfo", L"userx_id", userx_id);
	sb.Bind(L"nombre", tbxNombre);
	sb.Bind(L"domicilio", tbxDomicilio);
	sb.Bind(L"telefono", tbxTelefono);
	sb.Bind(L"edad", tbxEdad);
	sb.Bind(L"antecedentes", tbxAntef);
	sb.Bind(L"actividades", tbxActivf);
	sb.Bind(L"tiempo", tbxTiempo);
	sb.Bind(L"frecuencia", tbxActivfrec);
	sb.Bind(L"padecimientos_act", tbxPadact);
	sb.Bind(L"cirugias", tbxCirugias);
	sb.Bind(L"peso", tbxPeso);
	sb.Bind(L"altura", tbxAltura);
	sb.Bind(L"cadera", tbxCadera);
	sb.Bind(L"cintura", tbxCintura);
	sb.Bind(L"imc", tbxIMC);
	sb.Bind(L"comidas_aldia", tbxComd);
	sb.Bind(L"colaciones_aldia", tbxColacd);
	sb.Bind(L"consum_agua", tbxConsuag);
	sb.Bind(L"horarios_fijos", tbxHorafg);
	sb.Bind(L"salta_comidas", tbxSaltacomd);
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
		this->MessageBox(e.GetDescription(),L"Error", MB_OK| MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
	
}

void InfoClienteDlg::btCancelar_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

