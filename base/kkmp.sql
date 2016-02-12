﻿# SQL Manager 2010 for MySQL 4.5.0.9
# ---------------------------------------
# Host     : 192.168.10.252
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
  `id_inspection` int(11) NOT NULL auto_increment,
  `date_start` date NOT NULL default '0000-00-00',
  `date_end` date NOT NULL default '0000-00-00',
  `duration` int(11) NOT NULL default '0',
  `surname` varchar(35) NOT NULL default '',
  `name` varchar(35) NOT NULL default '',
  `patronymic` varchar(45) default NULL,
  `year_date_birthday` varchar(10) NOT NULL default '',
  `area` varchar(20) default NULL,
  `id_user` int(11) NOT NULL default '0',
  `RemarkInfServYes` int(1) default '0',
  `RemarkAnamYes` int(1) default '0',
  `RemarkFizResYes` int(1) default '0',
  `ResearchNotYes` int(1) default '0',
  `ResearchToMuchYes` int(1) default '0',
  `ResearchLateYes` int(1) default '0',
  `ResearchInstrNotYes` int(1) default '0',
  `ResearchInstrToMuchYes` int(1) default '0',
  `ResearchInstrLateYes` int(1) default '0',
  `RemarkKonsultNotYes` int(1) default '0',
  `RemarkKonsultLateYes` int(1) default '0',
  `RemarkDeseaseVerifYes` int(1) default '0',
  `RemarkDeseaseTimeYes` int(1) default '0',
  `RemarkDeseaseContentYes` int(1) default '0',
  `RemarkTherapyChooseDrYes` int(1) default '0',
  `RemarkTherapyTimeAppointmentYes` int(1) default '0',
  `RemarkTherapyPolypharmacyYes` int(1) default '0',
  `ContinuityChoosePlaceYes` int(1) default '0',
  `ContinuityTimeTransferYes` int(1) default '0',
  `RemarkStandartMHYes` int(1) default '0',
  `VuluntarMedAgreementYes` int(1) default '0',
  `AgreementPDNYes` int(1) default '0',
  `ComplitListDeseaseYes` int(1) default '0',
  `CompitListProfAndStatusYes` int(1) default '0',
  `ExistenceFLGYes` int(1) default '0',
  `ExistenceInspGinYes` int(1) default '0',
  `RationalUseOfResourcesYes` int(1) default '0',
  `AbsenceComplaintsOfPatientsYes` int(1) default '0',
  `TimelyRegistLNYes` int(1) default '0',
  `RefferalToVKYes` int(1) default '0',
  `IntegrityCard` int(1) default '1',
  `AccuracyHandwriting` int(1) default '1',
  `QualityProfInsOnko` int(1) default '1',
  `DispTimelines` int(1) default '1',
  `QualityCollectAnamsis` int(1) default '1',
  `QualityCollectComplaint` int(1) default '1',
  `DescriptObjectStatus` int(1) default '1',
  `EvaluationResultsOfTreatment` int(1) default '1',
  `ObservStandartsOfDiagnostics` int(1) default '1',
  `ObservStandartsOfTreatment` int(1) default '1',
  `DeadlinesVN` int(1) default '1',
  `kkmp` varchar(20) NOT NULL default '0',
  `kvo` varchar(20) NOT NULL default '0',
  `id_expert` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id_inspection`),
  UNIQUE KEY `id_inspection` (`id_inspection`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Structure for the `office` table : 
#

DROP TABLE IF EXISTS `office`;

CREATE TABLE `office` (
  `id_office` int(2) NOT NULL auto_increment,
  `name_office` varchar(150) NOT NULL default '',
  `id_user` int(11) default '1',
  PRIMARY KEY  (`id_office`),
  UNIQUE KEY `id_office` (`id_office`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Structure for the `user` table : 
#

DROP TABLE IF EXISTS `user`;

CREATE TABLE `user` (
  `id_user` int(11) NOT NULL auto_increment,
  `login` varchar(20) default NULL,
  `password` varchar(32) default NULL,
  `name` varchar(35) NOT NULL default '',
  `surname` varchar(45) NOT NULL default '',
  `patronymic` varchar(50) default NULL,
  `id_office` int(2) default '1',
  PRIMARY KEY  (`id_user`),
  UNIQUE KEY `id_user` (`id_user`),
  UNIQUE KEY `login` (`login`),
  UNIQUE KEY `login_2` (`login`),
  KEY `id_office` (`id_office`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for the `inspection` table  (LIMIT 0,500)
#

INSERT INTO `inspection` (`id_inspection`, `date_start`, `date_end`, `duration`, `surname`, `name`, `patronymic`, `year_date_birthday`, `area`, `id_user`, `RemarkInfServYes`, `RemarkAnamYes`, `RemarkFizResYes`, `ResearchNotYes`, `ResearchToMuchYes`, `ResearchLateYes`, `ResearchInstrNotYes`, `ResearchInstrToMuchYes`, `ResearchInstrLateYes`, `RemarkKonsultNotYes`, `RemarkKonsultLateYes`, `RemarkDeseaseVerifYes`, `RemarkDeseaseTimeYes`, `RemarkDeseaseContentYes`, `RemarkTherapyChooseDrYes`, `RemarkTherapyTimeAppointmentYes`, `RemarkTherapyPolypharmacyYes`, `ContinuityChoosePlaceYes`, `ContinuityTimeTransferYes`, `RemarkStandartMHYes`, `VuluntarMedAgreementYes`, `AgreementPDNYes`, `ComplitListDeseaseYes`, `CompitListProfAndStatusYes`, `ExistenceFLGYes`, `ExistenceInspGinYes`, `RationalUseOfResourcesYes`, `AbsenceComplaintsOfPatientsYes`, `TimelyRegistLNYes`, `RefferalToVKYes`, `IntegrityCard`, `AccuracyHandwriting`, `QualityProfInsOnko`, `DispTimelines`, `QualityCollectAnamsis`, `QualityCollectComplaint`, `DescriptObjectStatus`, `EvaluationResultsOfTreatment`, `ObservStandartsOfDiagnostics`, `ObservStandartsOfTreatment`, `DeadlinesVN`, `kkmp`, `kvo`, `id_expert`) VALUES 
  (3,'2016-02-12','2016-02-12',1,'ПЕТРОВ','В','В','1985','15',38,2,2,2,2,2,2,2,0,2,2,0,1,2,2,2,2,2,2,2,2,5,5,5,5,5,5,0,5,5,5,5,5,5,5,1,5,5,5,5,5,5,'1 / 0,943','0,056',93);
COMMIT;

#
# Data for the `office` table  (LIMIT 0,500)
#

INSERT INTO `office` (`id_office`, `name_office`, `id_user`) VALUES 
  (1,'не указано',1),
  (36,'Терапевтическое отделение №1',53),
  (37,'Терапевтическое отделение №2',81),
  (38,'Отделение общей врачебной практики',91),
  (39,'Хирургическое отделение',110),
  (40,'Отделение профилактики',86),
  (41,'Профпатологический кабинет',117),
  (42,'Стоматологическое отделение',126),
  (43,'Педиатрическое отделение №1',151),
  (44,'Педиатрическое отделение №2',161),
  (45,'Неврологический кабинет',173),
  (46,'Отделение организации медицинской помощи детям в образовательных учреждениях',176),
  (49,'Администрация',184);
COMMIT;

#
# Data for the `user` table  (LIMIT 0,500)
#

INSERT INTO `user` (`id_user`, `login`, `password`, `name`, `surname`, `patronymic`, `id_office`) VALUES 
  (1,'not','not','указано','не','',1),
  (2,'admin','21232F297A57A5A743894A0E4A801FC3','системы','Администратор','',1),
  (38,'абаевани','0D1B08C34858921BC7C662B228ACB7BA','НАДЕЖДА','АБАЕВА','ИЛЬИНИЧНА',36),
  (39,'андрееван','D41D8CD98F00B204E9800998ECF8427E','АРКАДИЙ','АНДРЕЕВ','НИКОЛАЕВИЧ',36),
  (40,'артемоваюа','D41D8CD98F00B204E9800998ECF8427E','ЮЛИЯ','АРТЕМОВА','АЛЕКСАНДРОВНА',36),
  (41,'вересоваин','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','ВЕРЕСОВА','НИКОЛАЕВНА',36),
  (42,'дмитриевавл','D41D8CD98F00B204E9800998ECF8427E','ВИКТОРИЯ','ДМИТРИЕВА','ЛЕОНИДОВНА',36),
  (43,'завьяловааа','D41D8CD98F00B204E9800998ECF8427E','АНАСТАСИЯ','ЗАВЬЯЛОВА','АЛЕКСАНДРОВНА',36),
  (44,'ивановаеа','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','ИВАНОВА','АЛЕКСАНДРОВНА',36),
  (45,'ларичевама','D41D8CD98F00B204E9800998ECF8427E','МАРГАРИТА','ЛАРИЧЕВА','АЛЕКСЕЕВНА',36),
  (46,'лихачевив','D41D8CD98F00B204E9800998ECF8427E','ИГОРЬ','ЛИХАЧЕВ','ВЕНИАМИНОВИЧ',36),
  (47,'морозованв','D41D8CD98F00B204E9800998ECF8427E','НАТАЛИЯ','МОРОЗОВА','ВИКТОРОВНА',36),
  (48,'муравьеваав','D41D8CD98F00B204E9800998ECF8427E','АНТОНИНА','МУРАВЬЕВА','ВАСИЛЬЕВНА',36),
  (49,'никановаив','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','НИКАНОВА','ВИКТОРОВНА',36),
  (50,'палицынала','D41D8CD98F00B204E9800998ECF8427E','ЛЮДМИЛА','ПАЛИЦЫНА','АЛЕКСАНДРОВНА',36),
  (51,'пироговни','D41D8CD98F00B204E9800998ECF8427E','НИКОЛАЙ','ПИРОГОВ','ИВАНОВИЧ',36),
  (52,'погодинала','D41D8CD98F00B204E9800998ECF8427E','ЛЮДМИЛА','ПОГОДИНА','АЛЕКСАНДРОВНА',36),
  (53,'пеи','0D1B08C34858921BC7C662B228ACB7BA','ЕВСТОЛИЯ','ПОДОЛЯК','ИВАНОВНА',36),
  (54,'сергачеванв','D41D8CD98F00B204E9800998ECF8427E','НАТАЛИЯ','СЕРГАЧЕВА','ВЛАДИМИРОВНА',36),
  (55,'соколовгв','D41D8CD98F00B204E9800998ECF8427E','ГЕОРГИЙ','СОКОЛОВ','ВАЛЕНТИНОВИЧ',36),
  (56,'талановакс','D41D8CD98F00B204E9800998ECF8427E','КАПИТОЛИНА','ТАЛАНОВА','СЕРГЕЕВНА',36),
  (57,'харевааг','D41D8CD98F00B204E9800998ECF8427E','АЛЕНА','ХАРЕВА','ГЕННАДЬЕВНА',36),
  (58,'чистяковаоа','D41D8CD98F00B204E9800998ECF8427E','ОКСАНА','ЧИСТЯКОВА','АНАТОЛЬЕВНА',36),
  (59,'шаабав','D41D8CD98F00B204E9800998ECF8427E','АЛЕКСАНДРА','ШААБ','ВАСИЛЬЕВНА',36),
  (60,'шабановалв','D41D8CD98F00B204E9800998ECF8427E','ЛЮДМИЛА','ШАБАНОВА','ВАСИЛЬЕВНА',36),
  (61,'шалабановдо','D41D8CD98F00B204E9800998ECF8427E','ДМИТРИЙ','ШАЛАБАНОВ','ОЛЕГОВИЧ',36),
  (62,'шароновамл','D41D8CD98F00B204E9800998ECF8427E','МАРИНА','ШАРОНОВА','ЛЕОНИДОВНА',36),
  (69,'баеваии','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','БАЕВА','ИВАНОВНА',37),
  (70,'благовестоваеа','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','БЛАГОВЕСТОВА','АНАТОЛЬЕВНА',37),
  (71,'гояеванн','D41D8CD98F00B204E9800998ECF8427E','НОННА','ГОЯЕВА','НОДАРОВНА',37),
  (72,'дякивничтк','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ДЯКИВНИЧ','КЛАВДИЕВНА',37),
  (73,'зайцевсв','D41D8CD98F00B204E9800998ECF8427E','СЕРГЕЙ','ЗАЙЦЕВ','ВЛАДИМИРОВИЧ',37),
  (74,'лавроваов','D41D8CD98F00B204E9800998ECF8427E','ОЛЕСЯ','ЛАВРОВА','ВЛАДИМИРОВНА',37),
  (75,'лентищевсн','D41D8CD98F00B204E9800998ECF8427E','СЕРГЕЙ','ЛЕНТИЩЕВ','НИКОЛАЕВИЧ',37),
  (76,'логиноваги','D41D8CD98F00B204E9800998ECF8427E','ГАЛИНА','ЛОГИНОВА','ИВАНОВНА',37),
  (77,'москаленкоав','D41D8CD98F00B204E9800998ECF8427E','АННА','МОСКАЛЕНКО','ВЛАДИМИРОВНА',37),
  (78,'нифановаас','D41D8CD98F00B204E9800998ECF8427E','АНАСТАСИЯ','НИФАНОВА','СЕРГЕЕВНА',37),
  (79,'новожиловаип','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','НОВОЖИЛОВА','ПАВЛОВНА',37),
  (80,'переломовди','D41D8CD98F00B204E9800998ECF8427E','ДМИТРИЙ','ПЕРЕЛОМОВ','ИГОРЕВИЧ',37),
  (81,'птн','0D1B08C34858921BC7C662B228ACB7BA','ТАТАЬЯНА','ПИШЕНИНА','НИКОЛАЕВНА',37),
  (82,'поповаов','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','ПОПОВА','ВИКТОРОВНА',37),
  (83,'прохороваиа','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','ПРОХОРОВА','АДОЛЬФОВНА',37),
  (84,'федюнинант','D41D8CD98F00B204E9800998ECF8427E','НАДЕЖДА','ФЕДЮНИНА','ТИМОФЕЕВНА',37),
  (85,'хренниковмв','D41D8CD98F00B204E9800998ECF8427E','МИХАИЛ','ХРЕННИКОВ','ВИТАЛЬЕВИЧ',37),
  (86,'шевердоваов','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','ШЕВЕРДОВА','ВЛАДИМИРОВНА',37),
  (87,'шулевалр','D41D8CD98F00B204E9800998ECF8427E','ЛИДИЯ','ШУЛЕВА','РОМАНОВНА',37),
  (88,'шучеввб','D41D8CD98F00B204E9800998ECF8427E','ВЛАДИМИР','ШУЧЕВ','БОРИСОВИЧ',37),
  (89,'бычковасп','D41D8CD98F00B204E9800998ECF8427E','СВЕТЛАНА','БЫЧКОВА','ПАВЛОВНА',38),
  (90,'воробьевате','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ВОРОБЬЕВА','ЕВГЕНЬЕВНА',38),
  (91,'жвг','0D1B08C34858921BC7C662B228ACB7BA','ВЕРА','ЖЕГАЛОВА','ГРИГОРЬЕВНА',38),
  (92,'игнатьеваин','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','ИГНАТЬЕВА','НИКОЛАЕВНА',38),
  (93,'кгт','0D1B08C34858921BC7C662B228ACB7BA','ГИВИ','КАЦИТАДЗЕ','ТЕНГИЗОВИЧ',49),
  (94,'лихачевавв','D41D8CD98F00B204E9800998ECF8427E','ВАЛЕНТИНА','ЛИХАЧЕВА','ВАЛЕНТИНОВНА',38),
  (95,'терениндв','D41D8CD98F00B204E9800998ECF8427E','ДАНИИЛ','ТЕРЕНИН','ВАЛЕНТИНОВИЧ',38),
  (96,'чулковатс','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ЧУЛКОВА','СЕРГЕЕВНА',38),
  (97,'ятченкома','D41D8CD98F00B204E9800998ECF8427E','МАРИНА','ЯТЧЕНКО','АРКАДЬЕВНА',38),
  (98,'байдаковааа','D41D8CD98F00B204E9800998ECF8427E','АННА','БАЙДАКОВА','АЛЕКСАНДРОВНА',35),
  (99,'егоровса','D41D8CD98F00B204E9800998ECF8427E','СТЕПАН','ЕГОРОВ','АЛЕКСАНДРОВИЧ',35),
  (100,'железняковаен','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','ЖЕЛЕЗНЯКОВА','НИКОЛАЕВНА',35),
  (101,'ивановвб','D41D8CD98F00B204E9800998ECF8427E','ВЛАДИМИР','ИВАНОВ','БОРИСОВИЧ',35),
  (102,'кирилюкаа','D41D8CD98F00B204E9800998ECF8427E','АЛЕКСАНДР','КИРИЛЮК','АНТОНОВИЧ',35),
  (103,'козицыналв','D41D8CD98F00B204E9800998ECF8427E','ЛАРИСА','КОЗИЦЫНА','ВИТАЛЬЕВНА',35),
  (104,'курочкинва','D41D8CD98F00B204E9800998ECF8427E','ВАСИЛИЙ','КУРОЧКИН','АЛЕКСАНДРОВИЧ',35),
  (105,'кускашевати','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','КУСКАШЕВА','ИВАНОВНА',35),
  (106,'липейна','D41D8CD98F00B204E9800998ECF8427E','НАТАЛЬЯ','ЛИПЕЙ','АЛЕКСАНДРОВНА',35),
  (107,'мизинцевате','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','МИЗИНЦЕВА','ЕВГЕНЬЕВНА',35),
  (108,'москвиновмю','D41D8CD98F00B204E9800998ECF8427E','МИХАИЛ','МОСКВИНОВ','ЮРЬЕВИЧ',35),
  (109,'николаевмс','D41D8CD98F00B204E9800998ECF8427E','ДМИТРИЙ','НИКОЛАЕВ','СЕРГЕЕВИЧ',35),
  (110,'ппп','0D1B08C34858921BC7C662B228ACB7BA','ПЕТР','ПОГОДИН','ПЕТРОВИЧ',35),
  (111,'сорочайкинсл','D41D8CD98F00B204E9800998ECF8427E','СЕРГЕЙ','СОРОЧАЙКИН','ЛЕОНИДОВИЧ',35),
  (112,'толстиковала','D41D8CD98F00B204E9800998ECF8427E','ЛЮДМИЛА','ТОЛСТИКОВА','АЛЕКСАНДРОВНА',35),
  (113,'трухалевсв','D41D8CD98F00B204E9800998ECF8427E','СЕРГЕЙ','ТРУХАЛЕВ','ВИКТОРОВИЧ',35),
  (114,'цаплинар','D41D8CD98F00B204E9800998ECF8427E','АНДРЕЙ','ЦАПЛИН','РУДОЛЬФОВИЧ',35),
  (115,'климовали','D41D8CD98F00B204E9800998ECF8427E','ЛЮБОВЬ','КЛИМОВА','ИВАНОВНА',40),
  (116,'щитинскаянп','D41D8CD98F00B204E9800998ECF8427E','НАДЕЖДА','ЩИТИНСКАЯ','ПАВЛОВНА',40),
  (117,'гулаковаа','D41D8CD98F00B204E9800998ECF8427E','АЛЕКСАНДР','ГУЛАКОВ','АЛЕКСАНДРОВИЧ',41),
  (118,'невзоровас','D41D8CD98F00B204E9800998ECF8427E','АЛЕКСАНДР','НЕВЗОРОВ','СТАНИСЛАВОВИЧ',41),
  (119,'селиванован','D41D8CD98F00B204E9800998ECF8427E','АНДРЕЙ','СЕЛИВАНОВ','НИКОЛАЕВИЧ',41),
  (120,'аюповаб','D41D8CD98F00B204E9800998ECF8427E','АНДРЕЙ','АЮПОВ','БОРИСОВИЧ',42),
  (121,'бардеевака','D41D8CD98F00B204E9800998ECF8427E','КЛАВДИЯ','БАРДЕЕВА','АЛЕКСАНДРОВНА',42),
  (122,'большакованг','D41D8CD98F00B204E9800998ECF8427E','НИНА','БОЛЬШАКОВА','ГЕРМАНОВНА',42),
  (123,'бурцевасв','D41D8CD98F00B204E9800998ECF8427E','СВЕТЛАНА','БУРЦЕВА','ВАЛЕРЬЕВНА',42),
  (124,'волкованв','D41D8CD98F00B204E9800998ECF8427E','НАДЕЖДА','ВОЛКОВА','ВЕНИАМИНОВНА',42),
  (125,'глазоватн','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ГЛАЗОВА','НИКОЛАЕВНА',42),
  (126,'кгя','0D1B08C34858921BC7C662B228ACB7BA','ГАЛИНА','КАПСКАЯ','ЯКОВЛЕВНА',42),
  (127,'кривошеинали','D41D8CD98F00B204E9800998ECF8427E','ЛЮБОВЬ','КРИВОШЕИНА','ИВАНОВНА',42),
  (128,'строгалеваоа','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','СТРОГАЛЕВА','АЛЕКСАНДРОВНА',42),
  (129,'тищенкоеа','D41D8CD98F00B204E9800998ECF8427E','ЕЛЕНА','ТИЩЕНКО','АЛЕКСАНДРОВНА',42),
  (130,'фальсовкинав','D41D8CD98F00B204E9800998ECF8427E','АЛЕКСАНДР','ФАЛЬСОВКИН','ВЯЧЕСЛАВОВИЧ',42),
  (131,'черепановеи','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЙ','ЧЕРЕПАНОВ','ИВАНОВИЧ',42),
  (132,'афонькинаса','D41D8CD98F00B204E9800998ECF8427E','СВЕТЛАНА','АФОНЬКИНА','АЛЕКСАНДРОВНА',43),
  (133,'бабченкоюв','D41D8CD98F00B204E9800998ECF8427E','ЮРИЙ','БАБЧЕНКО','ВИТАЛЬЕВИЧ',43),
  (134,'быковаоа','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','БЫКОВА','АНАТОЛЬЕВНА',43),
  (135,'димитровагм','D41D8CD98F00B204E9800998ECF8427E','ГАЛИНА','ДИМИТРОВА','МИХАЙЛОВНА',43),
  (136,'егороваэа','D41D8CD98F00B204E9800998ECF8427E','ЭЛЛА','ЕГОРОВА','АРКАДЬЕВНА',43),
  (137,'которовпв','D41D8CD98F00B204E9800998ECF8427E','ПЕТР','КОТОРОВ','ВЛАДИМИРОВИЧ',43),
  (138,'кочуроваги','D41D8CD98F00B204E9800998ECF8427E','ГАЛИНА','КОЧУРОВА','ИГОРЕВНА',43),
  (139,'кулаковаее','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','КУЛАКОВА','ЕВГЕНЬЕВНА',43),
  (140,'куликовалв','D41D8CD98F00B204E9800998ECF8427E','ЛЮБОВЬ','КУЛИКОВА','ВАСИЛЬЕВНА',43),
  (141,'лобановатл','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ЛОБАНОВА','ЛЕОНИДОВНА',43),
  (143,'матросовнн','D41D8CD98F00B204E9800998ECF8427E','НИКОЛАЙ','МАТРОСОВ','НИКОЛАЕВИЧ',43),
  (144,'моховаию','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','МОХОВА','ЮРЬЕВНА',43),
  (145,'наумоваиа','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','НАУМОВА','АЛЕКСАНДРОВНА',43),
  (146,'пономаренкоэв','D41D8CD98F00B204E9800998ECF8427E','ЭММА','ПОНОМАРЕНКО','ВЛАДИМИРОВНА',43),
  (147,'третьяковани','D41D8CD98F00B204E9800998ECF8427E','НАТАЛЬЯ','ТРЕТЬЯКОВА','ИВАНОВНА',43),
  (148,'труфановамв','D41D8CD98F00B204E9800998ECF8427E','МАРИЯ','ТРУФАНОВА','ВАСИЛЬЕВНА',43),
  (149,'федюковев','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЙ','ФЕДЮКОВ','ВИКТОРОВИЧ',43),
  (150,'шишкинаес','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','ШИШКИНА','СЕРГЕЕВНА',43),
  (151,'ятю','0D1B08C34858921BC7C662B228ACB7BA','ТАМАРА','ЯБЛОКОВА','ЮРЬЕВНА',43),
  (152,'агафоноваеа','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','АГАФОНОВА','АЛЕКСАНДРОВНА',44),
  (153,'ашуровамс','D41D8CD98F00B204E9800998ECF8427E','МАХБУБА','АШУРОВА','СОДИКОВНА',44),
  (154,'беседнована','D41D8CD98F00B204E9800998ECF8427E','НАТАЛЬЯ','БЕСЕДНОВА','АЛЕКСАНДРОВНА',44),
  (155,'брагинаон','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','БРАГИНА','НИКОЛАЕВНА',44),
  (156,'бургартзп','D41D8CD98F00B204E9800998ECF8427E','ЗОЯ','БУРГАРТ','ПАВЛОВНА',44),
  (157,'глушневатс','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ГЛУШНЕВА','СЕРГЕЕВНА',44),
  (158,'горюноватв','D41D8CD98F00B204E9800998ECF8427E','ТАМАРА','ГОРЮНОВА','ВАСИЛЬЕВНА',44),
  (159,'гурьеватм','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ГУРЬЕВА','МИХАЙЛОВНА',44),
  (160,'захароваел','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЯ','ЗАХАРОВА','ЛЕОНИДОВНА',44),
  (161,'изюмованл','D41D8CD98F00B204E9800998ECF8427E','НАТАЛЬЯ','ИЗЮМОВА','ЛЕОНИДОВНА',44),
  (162,'китаеванг','D41D8CD98F00B204E9800998ECF8427E','НАДЕЖДА','КИТАЕВА','ГРИГОРЬЕВНА',44),
  (163,'кобзевана','D41D8CD98F00B204E9800998ECF8427E','НАТАЛЬЯ','КОБЗЕВА','АЛЕКСАНДРОВНА',44),
  (164,'ковальчукюа','D41D8CD98F00B204E9800998ECF8427E','ЮЛИЯ','КОВАЛЬЧУК','АЛЕКСАНДРОВНА',44),
  (165,'колобовев','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЙ','КОЛОБОВ','ВЛАДИМИРОВИЧ',44),
  (166,'лощининавн','D41D8CD98F00B204E9800998ECF8427E','ВАЛЕНТИНА','ЛОЩИНИНА','НИКОЛАЕВНА',44),
  (167,'пермогорскаяин','D41D8CD98F00B204E9800998ECF8427E','ИРИНА','ПЕРМОГОРСКАЯ','НИКОЛАЕВН',44),
  (168,'репинос','D41D8CD98F00B204E9800998ECF8427E','ОЛЕГ','РЕПИН','СТАНИСЛАВОВИЧ',44),
  (169,'сафоноватн','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','САФОНОВА','НИКОЛАЕВНА',44),
  (170,'сигитоваоа','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','СИГИТОВА','АЛЕКСАНДРОВНА',44),
  (171,'смоленскийни','D41D8CD98F00B204E9800998ECF8427E','НИКОЛАЙ','СМОЛЕНСКИЙ','ИВАНОВИЧ',44),
  (172,'никулинва','D41D8CD98F00B204E9800998ECF8427E','ВАДИМ','НИКУЛИН','АЛЕКСАНДРОВИЧ',45),
  (173,'сучковаев','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЯ','СУЧКОВА','ВЛАДИМИРОВНА',45),
  (174,'тихановаев','D41D8CD98F00B204E9800998ECF8427E','ЕКАТЕРИНА','ТИХАНОВА','ВЛАДИМИРОВНА',45),
  (175,'хутареватв','D41D8CD98F00B204E9800998ECF8427E','ТАТЬЯНА','ХУТАРЕВА','ВИКТОРОВНА',45),
  (176,'бузыкаевавл','D41D8CD98F00B204E9800998ECF8427E','ВЕРА','БУЗЫКАЕВА','ЛЕОНИДОВНА',46),
  (177,'ермаковаон','D41D8CD98F00B204E9800998ECF8427E','ОЛЬГА','ЕРМАКОВА','НИКОЛАЕВНА',46),
  (178,'замятинала','D41D8CD98F00B204E9800998ECF8427E','ЛЮБОВЬ','ЗАМЯТИНА','АЛЕКСАНДРОВНА',46),
  (179,'курниковаев','D41D8CD98F00B204E9800998ECF8427E','ЕВГЕНИЯ','КУРНИКОВА','ВАСИЛЬЕВНА',46),
  (180,'райковавс','D41D8CD98F00B204E9800998ECF8427E','ВАЛЕРИЯ','РАЙКОВА','СЕРГЕЕВНА',46),
  (181,'сотоваса','D41D8CD98F00B204E9800998ECF8427E','СВЕТЛАНА','СОТОВА','АНАТОЛЬЕВНА',46),
  (182,'чудинованк','D41D8CD98F00B204E9800998ECF8427E','НИНА','ЧУДИНОВА','КОНСТАНТИНОВНА',46),
  (183,'шумовамн','D41D8CD98F00B204E9800998ECF8427E','МАРИЯ','ШУМОВА','НИКОЛАЕВНА',46),
  (184,'moa','A7CC11DECF703BBEFA04BE14514E469E','ОЛЬГА','МАРСОВА','АРНОЛЬДОВНА',49),
  (185,'sau','2405C79D70F52098B0647F79E96616D8','АНАТОЛИЙ','СОЛОВЬЁВ','ЮРЬЕВИЧ',49);
COMMIT;



/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;