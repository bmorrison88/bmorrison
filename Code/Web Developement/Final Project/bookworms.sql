-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Sep 10, 2017 at 01:34 PM
-- Server version: 5.7.19-0ubuntu0.16.04.1
-- PHP Version: 7.0.22-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bookworms`
--
CREATE DATABASE IF NOT EXISTS `bookworms` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `bookworms`;

-- --------------------------------------------------------

--
-- Table structure for table `currentreserver`
--

DROP TABLE IF EXISTS `currentreserver`;
CREATE TABLE IF NOT EXISTS `currentreserver` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `EID` varchar(255) NOT NULL COMMENT 'The eid of the user',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the user',
  `RoomReserved` int(11) NOT NULL COMMENT 'The room the user has reserved',
  `CurrentTime` timestamp NULL DEFAULT NULL COMMENT 'The current time used to see who is the current reserver',
  `User_Id` int(11) NOT NULL COMMENT 'FK references the User_Id of the schedule table',
  PRIMARY KEY (`Id`),
  KEY `users_user_id_fk` (`User_Id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `currentreserver`
--

TRUNCATE TABLE `currentreserver`;
-- --------------------------------------------------------

--
-- Table structure for table `room`
--

DROP TABLE IF EXISTS `room`;
CREATE TABLE IF NOT EXISTS `room` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `RoomNumber` varchar(11) NOT NULL COMMENT 'The room number',
  `Building` varchar(255) NOT NULL COMMENT 'The name of the building the room is in',
  `Floor` varchar(11) NOT NULL,
  `Description` text NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `room`
--

TRUNCATE TABLE `room`;
--
-- Dumping data for table `room`
--

INSERT INTO `room` (`Id`, `RoomNumber`, `Building`, `Floor`, `Description`) VALUES
(1, '1234', 'Lovejoy', '1', 'Test room #1'),
(2, '2457', 'Lovejoy', '2', 'Test room #2'),
(3, '1235', 'Engineering', '1', 'Test room #3'),
(8, '1895', 'Engineering', '1', 'This desc'),
(10, '1258', 'Lovejoy', '1', 'test'),
(9, '3688', 'Lovejoy', '3', 'Test room');

-- --------------------------------------------------------

--
-- Table structure for table `schedule`
--

DROP TABLE IF EXISTS `schedule`;
CREATE TABLE IF NOT EXISTS `schedule` (
  `id` int(100) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `startdate` varchar(20) NOT NULL,
  `enddate` varchar(20) NOT NULL,
  `starttime` varchar(20) NOT NULL,
  `endtime` varchar(20) NOT NULL,
  `color` varchar(20) NOT NULL,
  `url` varchar(50) NOT NULL,
  `user` varchar(20) NOT NULL,
  `building` varchar(45) NOT NULL,
  `roomnumber` varchar(45) NOT NULL,
  `removedstart` varchar(45) NOT NULL,
  `removedend` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `schedule`
--

TRUNCATE TABLE `schedule`;
--
-- Dumping data for table `schedule`
--

INSERT INTO `schedule` (`id`, `name`, `startdate`, `enddate`, `starttime`, `endtime`, `color`, `url`, `user`, `building`, `roomnumber`, `removedstart`, `removedend`) VALUES
(1, 'Reserved 1234', '2017-9-10', '', '8:00', '11:00', '#A44200', '', 'sewalte', 'Lovejoy', '1234', '8:00,9:00,10:00', '9:00,10:00,11:00'),
(2, 'Reserved 1895', '2017-10-2', '', '11:00', '14:00', '#A44200', '', 'sewalte', 'Engineering', '1895', '11:00,12:00,13:00', '12:00,13:00,14:00'),
(3, 'Reserved 1234', '2017-9-11', '', '9:00', '11:00', '#40BCD8', ' ', 'sewalte', 'Lovejoy', '1234', '9:00,10:00', '10:00,11:00'),
(4, 'Reserved 1895', '2017-9-11', '', '9:00', '11:00', '#A44200', '', 'sewalte', 'Engineering', '1895', '9:00,10:00', '10:00,11:00'),
(5, 'Reserved 1234', '2017-9-11', '', '7:00', '9:00', '#D63230', '', 'sewalte', 'Lovejoy', '1234', '7:00,8:00', '8:00,9:00'),
(6, 'Reserved 1234', '2017-9-10', '', '12:00', '13:00', '#068D9D', '', 'sewalte', 'Lovejoy', '1234', '12:00', '13:00');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `EID` varchar(255) NOT NULL COMMENT 'The eid of the user ',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the user',
  `Email` varchar(255) NOT NULL COMMENT 'The siue email of the user',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `user`
--

TRUNCATE TABLE `user`;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
