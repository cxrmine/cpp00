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

#include "./Account.hpp"
#include <ctime>
#include <iostream>

int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  Account::_totalAmount += initial_deposit;

  Account::_amount = initial_deposit;
  Account::_nbDeposits = 0;
  Account::_nbWithdrawals = 0;
  Account::_accountIndex = Account::_nbAccounts;

  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << Account::_accountIndex << ";";
  std::cout << "amount:" << Account::_amount << ";";
  std::cout << "created" << "\n";

  Account::_nbAccounts++;
}

Account::~Account(void) {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << Account::_accountIndex << ";";
  std::cout << "amount:" << Account::_amount << ";";
  std::cout << "closed" << "\n";
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "accounts:" << Account::_nbAccounts << ";";
  std::cout << "total:" << Account::_totalAmount << ";";
  std::cout << "deposits:" << Account::_totalNbDeposits << ";";
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
  Account::_amount += deposit;
  Account::_nbDeposits++;
  return;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_amount -= withdrawal;
  Account::_nbWithdrawals++;
  return true;
}

int Account::checkAmount(void) const { return Account::_amount; }

void Account::displayStatus(void) const {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << Account::_accountIndex << ";";
  std::cout << "amount:" << Account::_amount << ";";
  std::cout << "deposits:" << Account::_nbDeposits << ";";
  std::cout << "withdrawals:" << Account::_nbWithdrawals << "\n";
}

void Account::_displayTimestamp() {
  std::time_t t = std::time(NULL);
  char mbstr[100];

  if (std::strftime(mbstr, sizeof(mbstr), "%Y%m%d_%H%M%S", std::localtime(&t)))
    std::cout << mbstr;
}
