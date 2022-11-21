#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>

class FakeCantor {
 private:
  std::map<std::string, float> rates{{"USD", 1.0366f},
                                     {"GBP", 0.87063f},
                                     {"CHF", 0.9881f},
                                     {"JPY", 145.12f}};
 public:
  FakeCantor() = default;
  float EuroToRate(const std::string &currency) {
    return rates[currency];
  };
};

class Currency {
 public:
  virtual Currency *AddedCurrency(float value, std::string currency) = 0;
  virtual Currency *SubtractedCurrency(float value, std::string currency) = 0;
  virtual std::string Abbreviation() = 0;
  virtual std::string Symbol() = 0;
  virtual float Balance() = 0;
  virtual float DollarExchangeRate() = 0;
};

class Euro : public Currency {
  private:
	std::string Euro_Abbreviation = "EUR";
	std::string Euro_Symbol = "€";
	float Euro_Balance;
	float DollarExchangeRate_ToEuro= 0.9;

  public:
  Euro(float Euro_Balance){this->Euro_Balance=Euro_Balance;}
    Euro* AddedCurrency(float value, std::string Abbrevation) {
    	Euro* xd = new Euro2(value+Euro_Balance);
    	return xd;
    }
	std::string Abbreviation() {
		return Euro_Abbreviation;
	}
	std::string Symbol() {
		return Euro_Symbol;
	}
	float Balance() {
		return Euro_Balance;
	}
	float DollarExchangeRate() {
		return DollarExchangeRate_ToEuro;
	}
	
};

int main() {
  // TODO: showcase usage
  return 0;
}
