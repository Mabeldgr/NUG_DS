USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='NUGDB')
BEGIN 
	RAISERROR('Dropping existing whats database...', 0, 1)
	DROP DATABASE NUGDB;
END
GO

CREATE DATABASE NUGDB;
GO

USE NUGDB;
GO

IF db_name() <>'NUGDB'
BEGIN 
	RAISERROR('Use database failed...', 22, 127) WITH LOG
	DROP DATABASE NUGDB;
END
GO

--________________________________
IF NOT EXISTS(SELECT * FROM syslogins WHERE NAME='IIS AppPool\Sales')
BEGIN
	CREATE LOGIN [IIS AppPool\Sales] FROM WINDOWS;
END
GO

CREATE USER AppPoolUser FOR LOGIN [IIS AppPool\Sales];
GO

GRANT SELECT, INSERT, DELETE, UPDATE, EXECUTE TO [AppPoolUser];
GO

CREATE TABLE dbo.clienteinfo
(
	userx_id INT IDENTITY NOT NULL PRIMARY KEY,
	nombre VARCHAR(30) UNIQUE NOT NULL,
	domicilio VARCHAR(40) NOT NULL,
	telefono VARCHAR(15) NOT NULL,
	edad INT NOT NULL,
	antecedentes VARCHAR(200) NOT NULL,
	actividades VARCHAR(200) NOT NULL,
	tiempo VARCHAR (15) NOT NULL,
	frecuencia VARCHAR(50) NOT NULL,
	padecimientos_act VARCHAR(200) NOT NULL,
	cirugias VARCHAR (150) NOT NULL,
	peso INT NOT NULL, 
	altura INT NOT NULL,
	cadera INT NOT NULL,
	cintura INT NOT NULL,
	imc VARCHAR (10) NOT NULL,
	comidas_aldia INT NOT NULL,
	colaciones_aldia INT NULL,
	consum_agua VARCHAR (20)NOT NULL,
	horarios_fijos VARCHAR (15) NOT NULL,
	salta_comidas VARCHAR(15) NOT NULL,
)
GO

INSERT INTO clienteinfo(nombre,domicilio, telefono, edad, antecedentes, actividades,tiempo, frecuencia, padecimientos_act,cirugias,	peso, altura,cadera, cintura, imc, comidas_aldia, colaciones_aldia,consum_agua, horarios_fijos, salta_comidas)
			VALUES('Diana Garcia', 'Obregon 215', '111-111-1111', 20, 'Ninguno', 'Cardio, Yoga', '30 minutos','dos veces por semana', 'Ninguno',
					'Ninguno', 49, 164, 93, 65,'18.2', 3, 2,'si', 'Algunas veces', 'Poco frecuente');
INSERT INTO clienteinfo(nombre,domicilio, telefono, edad, antecedentes, actividades,tiempo, frecuencia, padecimientos_act,cirugias, peso, altura,cadera, cintura, imc, comidas_aldia, colaciones_aldia,consum_agua, horarios_fijos, salta_comidas)
			VALUES('Daniel Ortega', 'Tenixtepec', '222-222-2222', 22, 'Ninguno', 'Cardio, Pesas, Trote','Una hora', 'tres veces por semana', 'Ninguno', 'Ninguno', 75, 183, 85, 69,'22.4', 3, 3,'Casi dos litros' ,'No', 'Frecuentemente');

INSERT INTO clienteinfo(nombre,domicilio, telefono, edad, antecedentes, actividades,tiempo, frecuencia, padecimientos_act,
			cirugias, peso, altura,cadera, cintura, imc, comidas_aldia, colaciones_aldia, consum_agua, horarios_fijos, salta_comidas)
			VALUES('Maria Lopez', 'Muro 149', '471-241-1045', 21, 'Ninguno', 'Caminata', 'de 40 a 60 min', 'tres veces por semana', 'Ninguno',
			'Ninguno', 73, 166, 92, 80, '25.7', 3, 2, 'si', 'Si', 'Poco frecuente');

GO

CREATE TABLE dbo.cita
(
	userx_id INT NOT NULL REFERENCES clienteinfo(userx_id),
	cita_id INT IDENTITY NOT NULL,
	dieta VARCHAR(800) NOT NULL,
	fecha VARCHAR(20) NOT NULL,
	objetivos VARCHAR (50) NOT NULL,
	PRIMARY KEY(userx_id, cita_id)
)
GO
INSERT INTO cita(userx_id,dieta, fecha, objetivos) VALUES(1,'DESAYUNO Leche con avena o cereales y plátano en rebanadas. 
MEDIA MAÑANA	Té o café con tostadas o galletas con mermelada.
 COMIDA	Macarrones con salsa de brócoli, tomate y atún. 1 fruta fresca
 MERIENDA	Vaso de leche y bocadillo de pan integral con queso y tomate.
 CENA	Ternera a la plancha con ensalada de hojas verdes, zanahoria y granos de maíz. 1 fruta fresca',
'1 mayo de 2018', ' Bajar 800 gramos, reducción de trigleceridos');
--INSERT INTO cita(userx_id,dieta, fecha, objetivos) VALUES(1,'Desayuno: Tostada integral con tomate, aceite y kiwi.
--																			Media mañana: Piña.
--																			Comida:Ensalada de canónigos con nueces, parmesano y vinagreta de limón. Lubina al horno con eneldo.
--																			Media tarde: Yogur desnatado con chocolate negro.
--																			Cena:Verduras salteadas al estilo tailandés. Pollo con champiñones.
--																			Recena: Mandarina.','15 mayo de 2018', 'Aumento de masa muscular');
--INSERT INTO cita(userx_id,dieta, fecha, objetivos) VALUES(1 ,'Desayuno: Chapata con tomate, jamón y fruta.
--																			Media mañana:Mango.
--																			Comida: Verduras asadas con queso de cabra. Lomos de trucha al horno con tomate y cebolla.
--																			Media tarde: Compota de pera con canela.
--																			Cena: Crema de puerros. Pavo con cebolla, calabacín y salsa de soja.
--																			Recena: Manzana.','30 mayo de 2018', 'Reducir grasa ');
/*INSERT INTO cita(cuserx_id,dieta, fecha, objetivos) VALUES(2 ,'DESAYUNO: Leche con papilla de cereales. Azúcar o miel. Cacao.
																			MEDIA MAÑANA: Batido de yogur con fruta
																			COMIDA: Puré de verduras con arroz. Puré de merluza con bechamel. Natillas.
																			MERIENDA: Batido de leche con plátano y galletas.
																			CENA: Sémola de trigo o tapioca. Puré de pollo con patata y zanahoria. Yogur.
																			ANTES DE ACOSTARSE: Papilla de harina de maíz con azúcar, miel o cacao',
																			'13 abril de 2018', 'Ganar masa muscular y aumentar indices de minerales');*/
INSERT INTO cita(userx_id,dieta, fecha, objetivos) VALUES(2,'','13 abril de 2018', 'Reducir trigliceridos');





GO

select c.nombre as nombre, c.domicilio as domicilio, c.telefono as telefono, c.edad as edad, c.antecedentes as antecedentes, c.actividades as actividades, c.tiempo as tiempo, c.frecuencia as frecuencia, c.padecimientos_act as padecimientos_act, c.cirugias as cirugias, c.peso as peso, c.altura as altura, c.cadera as cadera, c.cintura as cintura, c.imc as imc, c.comidas_aldia as comidas_aldia, c.colaciones_aldia as colaciones_aldia, c.consum_agua as consum_agua, c.horarios_fijos as horarios_fijos, c.salta_comidas as salta_comidas
from clienteinfo c ,cita ci
where c.userx_id=ci.userx_id

Go