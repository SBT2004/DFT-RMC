// (C) Soczó Bálint
#pragma once

matrix* read_r_and_gr_from_csv(const char* path_to_csv);

void csv_out(const char* csv_out_file_path, const matrix* q_mat, const matrix* sq_mat);
