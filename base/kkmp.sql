# SQL Manager 2010 for MySQL 4.5.0.9
# ---------------------------------------
# Host     : localhost
# Port     : 3306
# Database : kkmp


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

SET FOREIGN_KEY_CHECKS=0;

DROP DATABASE IF EXISTS `kkmp`;

CREATE DATABASE `kkmp`
    CHARACTER SET 'latin1'
    COLLATE 'latin1_swedish_ci';

USE `kkmp`;

#
# Structure for the `inspection` table : 
#

DROP TABLE IF EXISTS `inspection`;

CREATE TABLE `inspection` (
  `id_inspection` int(11) NOT NULL AUTO_INCREMENT,
  `date_start` date NOT NULL,
  `date_end` date NOT NULL,
  `duration` int(11) NOT NULL DEFAULT '0',
  `surname` varchar(35) NOT NULL,
  `name` varchar(35) NOT NULL,
  `patronymic` varchar(45) DEFAULT NULL,
  `year_date_birthday` varchar(10) NOT NULL,
  `area` varchar(20) DEFAULT NULL,
  `id_user` int(11) NOT NULL,
  `RemarkInfServYes` int(1) DEFAULT '0',
  `RemarkAnamYes` int(1) DEFAULT '0',
  `RemarkFizResYes` int(1) DEFAULT '0',
  `ResearchNotYes` int(1) DEFAULT '0',
  `ResearchToMuchYes` int(1) DEFAULT '0',
  `ResearchLateYes` int(1) DEFAULT '0',
  `ResearchInstrNotYes` int(1) DEFAULT '0',
  `ResearchInstrToMuchYes` int(1) DEFAULT '0',
  `ResearchInstrLateYes` int(1) DEFAULT '0',
  `RemarkKonsultNotYes` int(1) DEFAULT '0',
  `RemarkKonsultLateYes` int(1) DEFAULT '0',
  `RemarkDeseaseVerifYes` int(1) DEFAULT '0',
  `RemarkDeseaseTimeYes` int(1) DEFAULT '0',
  `RemarkDeseaseContentYes` int(1) DEFAULT '0',
  `RemarkTherapyChooseDrYes` int(1) DEFAULT '0',
  `RemarkTherapyTimeAppointmentYes` int(1) DEFAULT '0',
  `RemarkTherapyPolypharmacyYes` int(1) DEFAULT '0',
  `ContinuityChoosePlaceYes` int(1) DEFAULT '0',
  `ContinuityTimeTransferYes` int(1) DEFAULT '0',
  `RemarkStandartMHYes` int(1) DEFAULT '0',
  `VuluntarMedAgreementYes` int(1) DEFAULT '0',
  `AgreementPDNYes` int(1) DEFAULT '0',
  `ComplitListDeseaseYes` int(1) DEFAULT '0',
  `CompitListProfAndStatusYes` int(1) DEFAULT '0',
  `ExistenceFLGYes` int(1) DEFAULT '0',
  `ExistenceInspGinYes` int(1) DEFAULT '0',
  `RationalUseOfResourcesYes` int(1) DEFAULT '0',
  `AbsenceComplaintsOfPatientsYes` int(1) DEFAULT '0',
  `TimelyRegistLNYes` int(1) DEFAULT '0',
  `RefferalToVKYes` int(1) DEFAULT '0',
  `IntegrityCard` int(1) DEFAULT '1',
  `AccuracyHandwriting` int(1) DEFAULT '1',
  `QualityProfInsOnko` int(1) DEFAULT '1',
  `DispTimelines` int(1) DEFAULT '1',
  `QualityCollectAnamsis` int(1) DEFAULT '1',
  `QualityCollectComplaint` int(1) DEFAULT '1',
  `DescriptObjectStatus` int(1) DEFAULT '1',
  `EvaluationResultsOfTreatment` int(1) DEFAULT '1',
  `ObservStandartsOfDiagnostics` int(1) DEFAULT '1',
  `ObservStandartsOfTreatment` int(1) DEFAULT '1',
  `DeadlinesVN` int(1) DEFAULT '1',
  `kkmp` varchar(20) NOT NULL DEFAULT '0',
  `kvo` varchar(20) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_inspection`),
  UNIQUE KEY `id_inspection` (`id_inspection`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

#
# Structure for the `office` table : 
#

DROP TABLE IF EXISTS `office`;

CREATE TABLE `office` (
  `id_office` int(2) NOT NULL AUTO_INCREMENT,
  `name_office` varchar(150) NOT NULL,
  `id_user` int(11) DEFAULT '0',
  PRIMARY KEY (`id_office`),
  UNIQUE KEY `id_office` (`id_office`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;

#
# Structure for the `user` table : 
#

DROP TABLE IF EXISTS `user`;

CREATE TABLE `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(20) DEFAULT NULL,
  `password` varchar(32) DEFAULT NULL,
  `name` varchar(35) NOT NULL,
  `surname` varchar(45) NOT NULL,
  `patronymic` varchar(50) DEFAULT NULL,
  `id_office` int(2) DEFAULT '1',
  PRIMARY KEY (`id_user`),
  UNIQUE KEY `id_user` (`id_user`),
  UNIQUE KEY `login` (`login`),
  UNIQUE KEY `login_2` (`login`),
  KEY `id_office` (`id_office`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;

#
# Data for the `office` table  (LIMIT 0,500)
#

INSERT INTO `office` (`id_office`, `name_office`, `id_user`) VALUES 
  (1,'не указано',0),
  (31,'1 Терапевтическое отделение',34),
  (32,'2 Терапевтическое отделение',33),
  (33,'Отделение общей практики',1),
  (34,'Хирургическое отделение',34);
COMMIT;

#
# Data for the `user` table  (LIMIT 0,500)
#

INSERT INTO `user` (`id_user`, `login`, `password`, `name`, `surname`, `patronymic`, `id_office`) VALUES 
  (1,'not','not','указано','не',' ',1),
  (2,'admin','21232F297A57A5A743894A0E4A801FC3','системы','Администратор','',1),
  (33,'kac','0208A2E72DA71F7D17D6D20080990AD0','ГИВИ','КАЦИТАДЗЕ','ТЕНГИЗОВИЧ',1),
  (34,'sol','12313A3D28F802E3A22B07D2E01C6DCF','АНАТОЛИЙ','СОЛОВЬЕВ','ЮРЬЕВИЧ',1);
COMMIT;



/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;