#pragma once

#include <base/shared_ptr_helper.h>
#include <Storages/IStorage.h>


namespace DB
{

class Context;


/** Implements storage for the system table One.
  * The table contains a single column of dummy UInt8 and a single row with a value of 0.
  * Used when the table is not specified in the query.
  * Analog of the DUAL table in Oracle and MySQL.
  */
class StorageSystemOne final : public shared_ptr_helper<StorageSystemOne>, public IStorage
{
    friend struct shared_ptr_helper<StorageSystemOne>;
public:
    std::string getName() const override { return "SystemOne"; }

    Pipe read(
        const Names & column_names,
        const StorageSnapshotPtr & storage_snapshot,
        SelectQueryInfo & query_info,
        ContextPtr context,
        QueryProcessingStage::Enum processed_stage,
        size_t max_block_size,
        unsigned num_streams) override;

    bool isSystemStorage() const override { return true; }

    bool supportsTransactions() const override { return true; }

protected:
    explicit StorageSystemOne(const StorageID & table_id_);
};

}
