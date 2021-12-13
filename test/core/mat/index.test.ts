import { Mat } from '../../../index'

describe('[core] Mat', () => {
  describe('constructor', () => {
    it('initializes empty', () => {
      const mat = new Mat()

      expect(mat.rows).toStrictEqual(0)
      expect(mat.cols).toStrictEqual(0)
    })
  })
})
