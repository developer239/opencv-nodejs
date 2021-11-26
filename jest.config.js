module.exports = {
  preset: 'ts-jest',
  transform: {
    '^.+\\.(ts|tsx)?$': 'babel-jest',
  },
  testPathIgnorePatterns: ['<rootDir>/cpp/', '<rootDir>/node_modules/'],
  setupFilesAfterEnv: [
    './jest.setup.ts'
  ]
}
