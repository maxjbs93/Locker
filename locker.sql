-- --------------------------------------------------------
-- Hôte:                         127.0.0.1
-- Version du serveur:           10.4.32-MariaDB - mariadb.org binary distribution
-- SE du serveur:                Win64
-- HeidiSQL Version:             12.10.0.7000
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Listage de la structure de table locker. casiers
CREATE TABLE IF NOT EXISTS `casiers` (
  `id_casier` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id unique du casier',
  `taille` varchar(10) DEFAULT NULL,
  `poids_max` decimal(5,2) DEFAULT NULL,
  `etat` enum('libre','occupé','en attente') DEFAULT NULL,
  `code` varchar(10) DEFAULT NULL COMMENT 'code pour ouvrir le casier',
  `id_commande` int(11) NOT NULL DEFAULT 0,
  `date_occupation` datetime DEFAULT NULL COMMENT 'Date et heure de l''occupation, NULL si libre',
  PRIMARY KEY (`id_casier`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=1032 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Listage des données de la table locker.casiers : ~20 rows (environ)
INSERT INTO `casiers` (`id_casier`, `taille`, `poids_max`, `etat`, `code`, `id_commande`, `date_occupation`) VALUES
	(1, 'petit', 5.00, 'libre', '0000', 0, '0000-00-00 00:00:00'),
	(2, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(3, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(4, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(5, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(6, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(7, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(8, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(9, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(10, 'petit', 5.00, 'libre', '0000', 0, NULL),
	(11, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(12, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(13, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(14, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(15, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(16, 'moyen', 10.00, 'libre', '0000', 0, NULL),
	(17, 'grand', 20.00, 'libre', '0000', 0, NULL),
	(18, 'grand', 20.00, 'libre', '0000', 0, NULL),
	(19, 'grand', 20.00, 'libre', '0000', 0, NULL),
	(20, 'grand', 20.00, 'libre', '0000', 0, NULL);

-- Listage de la structure de table locker. clients
CREATE TABLE IF NOT EXISTS `clients` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id unique du client',
  `prenom` varchar(50) DEFAULT NULL COMMENT 'prénom du client',
  `nom` varchar(50) DEFAULT NULL COMMENT 'nom du client',
  `email` varchar(50) DEFAULT NULL COMMENT 'email du client',
  `tel` varchar(50) DEFAULT NULL COMMENT 'numéro du client',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Listage des données de la table locker.clients : ~0 rows (environ)

-- Listage de la structure de table locker. commandes
CREATE TABLE IF NOT EXISTS `commandes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `client_email` varchar(255) NOT NULL,
  `taille_casier` varchar(50) NOT NULL,
  `poids_colis` decimal(10,2) NOT NULL,
  `commercant_nom` varchar(255) NOT NULL,
  `commercant_adresse` text NOT NULL,
  `date_creation` timestamp NOT NULL DEFAULT current_timestamp(),
  `client_id` int(11) DEFAULT NULL,
  `commercant_id` int(11) DEFAULT NULL,
  `statut` enum('en attente','en attente de confirmation','en cours','livrée') DEFAULT 'en attente',
  `livreur_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=120 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Listage des données de la table locker.commandes : ~4 rows (environ)
INSERT INTO `commandes` (`id`, `client_email`, `taille_casier`, `poids_colis`, `commercant_nom`, `commercant_adresse`, `date_creation`, `client_id`, `commercant_id`, `statut`, `livreur_id`) VALUES
	(107, 'maxime@gmail.com', 'petit', 2.50, 'Admin', '7 Rue Poulain', '2025-02-16 09:50:00', NULL, NULL, 'en cours', 1),
	(109, 'mathieu@gmail.com', 'petit', 1.00, 'Admin', '8 Avenue Chauve', '2025-02-16 10:12:40', NULL, NULL, 'en attente de confirmation', 1),
	(116, 'ishakabdoul@gmail.com', 'moyen', 6.00, 'Maxime', 'oui', '2025-02-19 09:30:04', NULL, NULL, 'en attente', NULL),
	(119, 'sdfsf', 'petit', 2.00, 'sdf', 'sdf', '2025-05-22 10:45:51', NULL, NULL, 'en attente', NULL);

-- Listage de la structure de table locker. commercants
CREATE TABLE IF NOT EXISTS `commercants` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id unique du commerçant',
  `prenom` varchar(50) DEFAULT NULL COMMENT 'prénom du commerçant',
  `nom` varchar(50) DEFAULT NULL COMMENT 'nom du commerçant',
  `email` varchar(50) DEFAULT NULL COMMENT 'email du commerçant',
  `tel` varchar(50) DEFAULT NULL COMMENT 'téléphone du commerçant',
  `adresse` varchar(100) DEFAULT NULL COMMENT 'Adresse du magasin',
  `pseudo` varchar(50) DEFAULT NULL,
  `mdp` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=101 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Listage des données de la table locker.commercants : ~2 rows (environ)
INSERT INTO `commercants` (`id`, `prenom`, `nom`, `email`, `tel`, `adresse`, `pseudo`, `mdp`) VALUES
	(1, 'Maxime', 'SFRISO', 'maximesfriso@gmail.com', '0606060606', '14 Rue Polnareff', 'Admin', 'test'),
	(2, 'Elhanafi', 'TEGUIG', 'elhanafiteguig@gmail.com', '0758430970', '9 avenue du bidonville', 'Teguig_Jbs', 'test');

-- Listage de la structure de table locker. livreurs
CREATE TABLE IF NOT EXISTS `livreurs` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id unique du livreur',
  `prenom` varchar(50) NOT NULL DEFAULT '' COMMENT 'prenom du livreur',
  `nom` varchar(50) NOT NULL DEFAULT '' COMMENT 'nom du livreur',
  `adresse` varchar(50) DEFAULT NULL,
  `email` varchar(50) NOT NULL DEFAULT '' COMMENT 'email du livreur',
  `tel` varchar(50) DEFAULT NULL COMMENT 'téléphone du livreur',
  `username` varchar(50) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `statut` enum('disponible','en attente','en attente de confirmation','en cours de livraison') DEFAULT 'disponible',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=116 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Listage des données de la table locker.livreurs : ~5 rows (environ)
INSERT INTO `livreurs` (`id`, `prenom`, `nom`, `adresse`, `email`, `tel`, `username`, `password`, `statut`) VALUES
	(1, 'Maxime', 'SFRISO', '4 Avenue du 4 ', 'maxime@gmail.com', '0604050203', 'max_jbs', 'maxou', 'en attente de confirmation'),
	(2, 'Rayane', 'GERVAIS', '4 Place des Aubépines', '', NULL, 'rayane_gervais', 'rgervais', 'disponible'),
	(3, 'qsdf', 'qsdf', 'qsdf', '', NULL, 'sdfq', 'sf', 'disponible'),
	(114, 'qsd', 'qsdfdsq', 'sqd', '', NULL, 'fsfsf', 'fsfsf', 'disponible'),
	(115, 'sdf', 'sdf', 'sdf', '', NULL, 'sdf', 'dsf', 'disponible');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
