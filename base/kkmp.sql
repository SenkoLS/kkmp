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
  `type_med_help` int(2) NOT NULL,
  `date_start` date NOT NULL,
  `date_end` date NOT NULL,
  `surname` varchar(35) NOT NULL,
  `name` varchar(35) NOT NULL,
  `patronymic` varchar(45) DEFAULT NULL,
  `date_birthday` date NOT NULL,
  `number_card` varchar(45) DEFAULT '-',
  `id_med` int(11) NOT NULL,
  `kkmp` double(15,3) NOT NULL DEFAULT '0.000',
  `kvo` double(15,3) NOT NULL DEFAULT '0.000',
  PRIMARY KEY (`id_inspection`),
  UNIQUE KEY `id_inspection` (`id_inspection`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for the `office` table : 
#

DROP TABLE IF EXISTS `office`;

CREATE TABLE `office` (
  `id_office` int(2) NOT NULL AUTO_INCREMENT,
  `name_office` varchar(150) NOT NULL,
  `id_user` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_office`),
  UNIQUE KEY `id_office` (`id_office`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

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
  `id_office` int(2) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id_user`),
  UNIQUE KEY `id_user` (`id_user`),
  UNIQUE KEY `login` (`login`),
  UNIQUE KEY `login_2` (`login`),
  KEY `id_office` (`id_office`),
  CONSTRAINT `user_fk` FOREIGN KEY (`id_office`) REFERENCES `office` (`id_office`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

#
# Data for the `inspection` table  (LIMIT 0,500)
#

INSERT INTO `inspection` (`id_inspection`, `type_med_help`, `date_start`, `date_end`, `surname`, `name`, `patronymic`, `date_birthday`, `number_card`, `id_med`, `kkmp`, `kvo`) VALUES 
  (1,1,'2016-01-01','2016-01-10','ИВАНОВ','ИВАН','ПЕТРОВИЧ','1939-11-07','14',2,0.885,0.200),
  (2,2,'2016-01-01','2016-01-12','ПЕТРОВ','ПЕТР','ИВАНОВИЧ','1957-04-12','15',1,0.458,0.450);
COMMIT;

#
# Data for the `office` table  (LIMIT 0,500)
#

INSERT INTO `office` (`id_office`, `name_office`, `id_user`) VALUES 
  (1,'не указано',NULL),
  (3,'1 Терапевтическое отделение',NULL),
  (4,'2 Терапевтическое отделение',NULL),
  (5,'Отделение общей практики',NULL),
  (6,'Хирургическое отделение',NULL);
COMMIT;

#
# Data for the `user` table  (LIMIT 0,500)
#

INSERT INTO `user` (`id_user`, `login`, `password`, `name`, `surname`, `patronymic`, `id_office`) VALUES 
  (1,'admin','21232f297a57a5a743894a0e4a801fc3','Админ',' ','',1),
  (2,'kacgt','21232f297a57a5a743894a0e4a801fc3','ГИВИ','КАЦИТАДЗЕ','ТЕНГИЗОВИЧ',1),
  (3,'','','ВЕРА','БУЗЫКАЕВА','ЛЕОНИДОВНА',1);
COMMIT;



/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;