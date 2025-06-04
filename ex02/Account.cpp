/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:01:35 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/04 14:01:35 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) {}

Account::~Account(void) {}

int Account::getNbAccounts(void) {
	return 0;
}

int Account::getTotalAmount(void) {
	return 0;
}

int Account::getNbDeposits(void) {
	return 0;
}

int Account::getNbWithdrawals(void) {
	return 0;
}

void Account::displayAccountsInfos(void) {
	std::cout << "[";
	Account::_displayTimestamp();
	std::cout << "] ";
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawal:" << Account::_totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
	return ;
}

bool Account::makeWithdrawal(int withdrawal) {
	return false;
}

int Account::checkAmount(void) const {
	return 0;
}

void Account::displayStatus(void) const {
	return ;
}
