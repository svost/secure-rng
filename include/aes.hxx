/*
 * Copyright (C) 2017 Nagravision S.A.
 */
#ifndef AES_H
#define AES_H

#include <cstdint>
#include <array>
#include <vector>


constexpr uint32_t Nb = 4;
constexpr uint32_t Nk = 8;        // The number of 32 bit words in a key.
constexpr uint32_t Nr = 14;       // The number of rounds in AES Cipher.
constexpr uint32_t AES_BLOCKLEN = 16; // Block length in bytes - AES is 128b block only
constexpr uint32_t AES_keyExpSize = 240; // 16*15 or 16*(Nr+1)

/**
 * AES key bytes array
 */
using aes_key_t = std::array<uint8_t, 4 * Nk>;

/**
 * AES block array
 */
using aes_block_t = std::array<uint8_t, AES_BLOCKLEN>;

#ifdef SOFTWARE_FALLBACK
void aesctr256_software (std::vector<aes_block_t> &out, const aes_key_t &sk, const aes_block_t &counter);
void aesctr256_zeroiv_software (std::vector<aes_block_t> &out, const aes_key_t &sk);
#endif

#ifdef HARDWARE_SUPPORT
void aesctr256_hardware (std::vector<aes_block_t> &out, const aes_key_t &sk, const aes_block_t &counter);
void aesctr256_zeroiv_hardware (std::vector<aes_block_t> &out, const aes_key_t &sk);
int aes_hardware_supported();
#endif

#endif // AES_H
