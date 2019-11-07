﻿#pragma once
#include <iostream>
#include <vector>

namespace winapi {
	enum class show {normal, noactive};

	class win32_error
	{
	public:
		win32_error(int code);
		std::wstring message();
	private:
		int code;
	};

	void execute(std::wstring exec, std::wstring parameters, show show);

	void show_window(long handle);
	void active_window(long handle);
	long get_main_window_handle(const long pid);

	std::string wide2multi(std::wstring const& str, unsigned int codepage);
	std::wstring multi2wide(std::string const& str, unsigned int codepage);

	std::wstring expand_environment_strings(std::wstring str);

	std::wstring uri2path(std::wstring uri);
	std::wstring path2uri(std::wstring uri);

	unsigned int get_console_output_codepage();
	unsigned int set_console_output_codepage(unsigned int codepage);
	std::wstring get_console_title();
	void set_console_title(std::wstring title);

	int get_current_process_id();
	struct process_entry {
		DWORD process_id;
		int window_text_length;
		long window_handle;
	};
	std::vector<process_entry> get_process_entries(std::wstring name);

	long get_registry_value(std::wstring key, std::wstring name, long default_value);
}
	