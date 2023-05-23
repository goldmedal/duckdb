//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/catalog/default/builtin_types/types.hpp
//
//
//===----------------------------------------------------------------------===//
// This file is generated by scripts/generate_builtin_types.py

#pragma once

#include "duckdb/common/types.hpp"
#include "duckdb/common/case_insensitive_map.hpp"

namespace duckdb {

LogicalTypeId GetBuiltinType(const string &type) {
	static const std::pair<std::string, LogicalTypeId> types[] = {
		{"hugeint", LogicalTypeId::HUGEINT},
		{"int128", LogicalTypeId::HUGEINT},
		{"bigint", LogicalTypeId::BIGINT},
		{"oid", LogicalTypeId::BIGINT},
		{"long", LogicalTypeId::BIGINT},
		{"int8", LogicalTypeId::BIGINT},
		{"int64", LogicalTypeId::BIGINT},
		{"ubigint", LogicalTypeId::UBIGINT},
		{"uint64", LogicalTypeId::UBIGINT},
		{"integer", LogicalTypeId::INTEGER},
		{"int", LogicalTypeId::INTEGER},
		{"int4", LogicalTypeId::INTEGER},
		{"signed", LogicalTypeId::INTEGER},
		{"integral", LogicalTypeId::INTEGER},
		{"int32", LogicalTypeId::INTEGER},
		{"uinteger", LogicalTypeId::UINTEGER},
		{"uint32", LogicalTypeId::UINTEGER},
		{"smallint", LogicalTypeId::SMALLINT},
		{"int2", LogicalTypeId::SMALLINT},
		{"short", LogicalTypeId::SMALLINT},
		{"int16", LogicalTypeId::SMALLINT},
		{"usmallint", LogicalTypeId::USMALLINT},
		{"uint16", LogicalTypeId::USMALLINT},
		{"tinyint", LogicalTypeId::TINYINT},
		{"int1", LogicalTypeId::TINYINT},
		{"utinyint", LogicalTypeId::UTINYINT},
		{"uint8", LogicalTypeId::UTINYINT},
		{"float", LogicalTypeId::FLOAT},
		{"real", LogicalTypeId::FLOAT},
		{"float4", LogicalTypeId::FLOAT},
		{"double", LogicalTypeId::DOUBLE},
		{"float8", LogicalTypeId::DOUBLE},
		{"decimal", LogicalTypeId::DECIMAL},
		{"dec", LogicalTypeId::DECIMAL},
		{"numeric", LogicalTypeId::DECIMAL},
		{"time", LogicalTypeId::TIME},
		{"date", LogicalTypeId::DATE},
		{"timestamp", LogicalTypeId::TIMESTAMP},
		{"datetime", LogicalTypeId::TIMESTAMP},
		{"timestamp_us", LogicalTypeId::TIMESTAMP},
		{"timestamp_ms", LogicalTypeId::TIMESTAMP_MS},
		{"timestamp_ns", LogicalTypeId::TIMESTAMP_NS}
	};
	static const case_insensitive_map_t<LogicalTypeId> type_map(types, types + (sizeof(types) / sizeof(std::pair<std::string, LogicalTypeId>)));
	auto entry = type_map.find(type);
	if (entry == type_map.end()) {
		return LogicalType::INVALID;
	}
	return entry->second;
}

} // namespace duckdb
