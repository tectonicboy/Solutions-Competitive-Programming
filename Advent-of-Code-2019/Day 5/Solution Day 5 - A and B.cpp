#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>
#include <tuple>
#include <fstream>

using namespace std;

vector<string> CreateNumbersVec(string& s) {
	vector<string> vec = {};
	string dummy = "";
	for (size_t i = 0; i < s.size(); ++i) {
		while (!((s[i] == ',') || (i == s.size() - 1))) {
			dummy.push_back(s[i]);
			++i;
		}
		if (s[i] == ',') {
			vec.push_back(dummy);
			dummy = "";
			continue;
		}
		else if (i == s.size() - 1) {
			dummy.push_back(s[i]);
			vec.push_back(dummy);
			dummy = "";
			return vec;
		}
	}
}

class IntcodeComputer {
public:
	vector<string> m_program = {};
	int program_counter = 0;
	IntcodeComputer(string& program) : m_program(CreateNumbersVec(program)) {
		//m_program = CreateNumbersVec(program);
	};

	void setProgram(string& program) {
		m_program = CreateNumbersVec(program);
	}

	void run(void) {
		if (m_program.size() == 0) {
			cout << "ERROR: No program loaded in computer to run.\n";
			return;
		}
		else {
			size_t INS_P = 0;
			vector<int> param_modes = {}, operands = {};
			string index_s = "", val_s = "";
			int index_i = 0, val_i = 0, ins_counter = 0;
			while (m_program[INS_P] != "99") {
				++ins_counter;
				//if (ins_counter == 20) {
				//	return;
				//}
				cout << "\n ***************************** INSTRUCTION " << ins_counter << " *****************************\n\n";
				cout << "INS_P = " << INS_P << "\n";
				string ins_info = m_program[INS_P];
				if (ins_info.size() == 1) {
					ins_info.insert(0, 1, '0');
				}
				cout << "ins_info has been initialized to: " << ins_info << "\n";
				string op_code(ins_info.end() - 2, ins_info.end());
				cout << "op_code has been initialized to: " << op_code << "\n";
				//Multiplication and addition handlers.
				if (op_code == "01" || op_code == "02") {
					while (ins_info.size() < 5) {
						ins_info.insert(0, 1, '0');
					}
					operands = { 0, 0, 0 };
					//Get the parameter mode of each of the 3 parameters.
					for (int i = ins_info.size() - 3; i >= 0; --i) {
						if (ins_info[i] == '0') {
							param_modes.push_back(0);
						}
						else {
							param_modes.push_back(1);
						}
					}
					//Populate the actual numbers to mul / add based on their param modes.
					cout << "parameter modes look like this: ";
					for (size_t i = 0; i < param_modes.size(); ++i) {
						cout << param_modes[i] << " ";
					}
					cout << "\n";
					for (int i = 0; i < param_modes.size(); ++i) {
						if (param_modes[i] == 0) {
							index_s = m_program[INS_P + (i+1)];
							index_i = stoi(index_s);
							val_s = m_program[index_i];
							val_i = stoi(val_s);	
							operands[i] = val_i;
							cout << "CAPTURED the value " << val_i << " from index [" << index_i << "]\n";
						}
						else {
							val_s = m_program[INS_P + (i+1)];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "The value became the value: " << val_i << "\n";
						}
					}
					operands[2] = stoi(m_program[INS_P + 3]);
					//Addition.
					if (op_code == "01") {
						cout << "operands.size() = " << operands.size() << ", operands[0] = " << operands[0]
							<< ", operands[1] = " << operands[1] << ", operands[2] = " << operands[2] << "\n";
						cout << "m_program.size() = " << m_program.size() << "\n";
						cout << "***** Writing result of addition " << operands[0] << " + " << operands[1] << " = " << to_string(operands[0] + operands[1]) << " to address m_program["
							<< stoi(m_program[INS_P + 3]) << "].\n";
						m_program[stoi(m_program[INS_P + 3])] = to_string(operands[0] + operands[1]);
						param_modes = {};
						INS_P += 4;
						continue;
					}
					//Multiplication.
					else {
						cout << "***** Writing result of multiplication " << operands[0] << " * " << operands[1] << " = " << to_string(operands[0] * operands[1]) << " to address m_program["
							<< stoi(m_program[INS_P + 3]) << "].\n";
						m_program[stoi(m_program[INS_P + 3])] = to_string(operands[0] * operands[1]);
						param_modes = {};
						INS_P += 4;
						continue;
					}
				}
				//Input
				else if (op_code == "03") {
					while (ins_info.size() < 3) {
						ins_info.insert(0, 1, '0');
					}
					int input = 0;
					cin >> input;
					m_program[stoi(m_program[INS_P + 1])] = to_string(input);
					INS_P += 2;
					continue;
				}
				//Output
				else if (op_code == "04") {
					while (ins_info.size() < 3) {
						ins_info.insert(0, 1, '0');
					}
					cout << m_program[stoi(m_program[INS_P + 1])];
					INS_P += 2;
					continue;
				}
				//Jump-If-True
				else if (op_code == "05") {
					while (ins_info.size() < 4) {
						ins_info.insert(0, 1, '0');
					}
					operands = { 0, 0 };
					//Get the parameter mode of each of the 3 parameters.
					for (int i = ins_info.size() - 3; i >= 0; --i) {
						if (ins_info[i] == '0') {
							param_modes.push_back(0);
						}
						else {
							param_modes.push_back(1);
						}
					}
					//Populate the actual numbers to mul / add based on their param modes.
					cout << "parameter modes look like this: ";
					for (size_t i = 0; i < param_modes.size(); ++i) {
						cout << param_modes[i] << " ";
					}
					cout << "\n";
					for (int i = 0; i < param_modes.size(); ++i) {
						if (param_modes[i] == 0) {
							index_s = m_program[INS_P + (i + 1)];
							index_i = stoi(index_s);
							val_s = m_program[index_i];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "CAPTURED the value " << val_i << " from index [" << index_i << "]\n";
						}
						else {
							val_s = m_program[INS_P + (i + 1)];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "The value became the value: " << val_i << "\n";
						}
					}
					if (operands[0] != 0) {
						cout << "***** SETTING INS_P to: " << operands[1] << " *****\n";
						INS_P = operands[1];
						param_modes = {};
						continue;
					}
					else {
						param_modes = {};
						INS_P += 3;
						continue;
					}
				}
				//Jump-If-False
				else if (op_code == "06") {
					while (ins_info.size() < 4) {
						ins_info.insert(0, 1, '0');
					}
					operands = { 0, 0 };
					//Get the parameter mode of each of the 3 parameters.
					for (int i = ins_info.size() - 3; i >= 0; --i) {
						if (ins_info[i] == '0') {
							param_modes.push_back(0);
						}
						else {
							param_modes.push_back(1);
						}
					}
					//Populate the actual numbers to mul / add based on their param modes.
					cout << "parameter modes look like this: ";
					for (size_t i = 0; i < param_modes.size(); ++i) {
						cout << param_modes[i] << " ";
					}
					cout << "\n";
					for (int i = 0; i < param_modes.size(); ++i) {
						if (param_modes[i] == 0) {
							index_s = m_program[INS_P + (i + 1)];
							index_i = stoi(index_s);
							val_s = m_program[index_i];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "CAPTURED the value " << val_i << " from index [" << index_i << "]\n";
						}
						else {
							val_s = m_program[INS_P + (i + 1)];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "The value became the value: " << val_i << "\n";
						}
					}
					if (operands[0] == 0) {
						cout << "***** SETTING INS_P to: " << operands[1] << " *****\n";
						INS_P = operands[1];
						param_modes = {};
						continue;
					}
					else {
						param_modes = {};
						INS_P += 3;
						continue;
					}
				}
				//Less than
				else if (op_code == "07") {
					while (ins_info.size() < 5) {
						ins_info.insert(0, 1, '0');
					}
					operands = { 0, 0, 0 };
					//Get the parameter mode of each of the 3 parameters.
					for (int i = ins_info.size() - 3; i >= 0; --i) {
						if (ins_info[i] == '0') {
							param_modes.push_back(0);
						}
						else {
							param_modes.push_back(1);
						}
					}
					//Populate the actual numbers to mul / add based on their param modes.
					cout << "parameter modes look like this: ";
					for (size_t i = 0; i < param_modes.size(); ++i) {
						cout << param_modes[i] << " ";
					}
					cout << "\n";
					for (int i = 0; i < param_modes.size(); ++i) {
						if (param_modes[i] == 0) {
							index_s = m_program[INS_P + (i+1)];
							index_i = stoi(index_s);
							val_s = m_program[index_i];
							val_i = stoi(val_s);	
							operands[i] = val_i;
							cout << "CAPTURED the value " << val_i << " from index [" << index_i << "]\n";
						}
						else {
							val_s = m_program[INS_P + (i+1)];
							val_i = stoi(val_s);
							operands[i] = val_i;
							cout << "The value became the value: " << val_i << "\n";
						}
					}
					if (operands[0] < operands[1]) {
						cout << "*****Putting value 1 in m_program[" << stoi(m_program[INS_P + 3]) << "]*****\n";
						m_program[stoi(m_program[INS_P + 3])] = "1";
						param_modes = {};
						INS_P += 4;
						continue;
					}
					else {
						cout << "*****Putting value 0 in m_program[" << stoi(m_program[INS_P + 3]) << "]*****\n";
						m_program[stoi(m_program[INS_P + 3])] = "0";
						param_modes = {};
						INS_P += 4;
						continue;
					}
				}
				//Equals
				else if (op_code == "08") {
				while (ins_info.size() < 5) {
					ins_info.insert(0, 1, '0');
				}
				operands = { 0, 0, 0 };
				//Get the parameter mode of each of the 3 parameters.
				for (int i = ins_info.size() - 3; i >= 0; --i) {
					if (ins_info[i] == '0') {
						param_modes.push_back(0);
					}
					else {
						param_modes.push_back(1);
					}
				}
				//Populate the actual numbers to mul / add based on their param modes.
				cout << "parameter modes look like this: ";
				for (size_t i = 0; i < param_modes.size(); ++i) {
					cout << param_modes[i] << " ";
				}
				cout << "\n";
				for (int i = 0; i < param_modes.size(); ++i) {
					if (param_modes[i] == 0) {
						index_s = m_program[INS_P + (i + 1)];
						index_i = stoi(index_s);
						val_s = m_program[index_i];
						val_i = stoi(val_s);
						operands[i] = val_i;
						cout << "CAPTURED the value " << val_i << " from index [" << index_i << "]\n";
					}
					else {
						val_s = m_program[INS_P + (i + 1)];
						val_i = stoi(val_s);
						operands[i] = val_i;
						cout << "The value became the value: " << val_i << "\n";
					}
				}
				if (operands[0] == operands[1]) {
					cout << "*****Putting value 1 in m_program[" << stoi(m_program[INS_P + 3]) << "]*****\n";
					m_program[stoi(m_program[INS_P + 3])] = "1";
					param_modes = {};
					INS_P += 4;
					continue;
				}
				else {
					cout << "*****Putting value 0 in m_program[" << stoi(m_program[INS_P + 3]) << "]*****\n";
					m_program[stoi(m_program[INS_P + 3])] = "0";
					param_modes = {};
					INS_P += 4;
					continue;
				}
				}
			}
		}
	}
};

int main() {
	static string input_program = "";
	cin >> input_program;
	IntcodeComputer computer1(input_program);
	computer1.run();
	return 0;
}